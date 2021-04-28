/*
 * Implementation of a Binary Heap data structure. 
 * The `m_map` field is added to be used with Dijkstra's algorithm.
 * TODO: Implement Fibonacci Heap
 */
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cmath>
#include <map>


int left_child_index(size_t index) {
    return 2 * index + 1;
}
int right_child_index(size_t index) {
    return 2 * index + 2;
}
int parent_index(size_t index) {
    return (index - 1) / 2;
}

template <typename T, typename Compare = std::greater<T>, typename CompareMap = std::less<T>>
class BinaryHeap {
    protected:
        std::vector<T> m_data;
        Compare m_comp;

    public:
        std::map<T, size_t, CompareMap> m_map;

    public:

        // Creation
        BinaryHeap(Compare comp = Compare()): m_data({}), m_comp(comp), m_map() { }
        BinaryHeap(std::vector<T>& data, Compare comp = Compare()): m_data(data), m_comp(comp) { 
            for(int i = 0; i < m_data.size(); i++) {
                m_map[m_data[i]] = i;
            }
            for(int i = m_data.size() / 2 - 1; i >= 0; i--) {
                heapify_down(i);
            }
        }
        void merge(const BinaryHeap<T, Compare>& other, BinaryHeap<T, Compare>& result, bool clear=true) const {
            auto merged_data = std::vector<T>();
            merged_data.insert(merged_data.end(), m_data.begin(), m_data.end());
            merged_data.insert(merged_data.end(), other.m_data.begin(), other.m_data.end());
            result.clear();
            result.set_data(merged_data);
        }
        void meld(BinaryHeap<T, Compare>& other) {
            for(auto const& d : other.m_data) {
                push(d);
            }
        }

        // Basic
        const T& peek() const {
            return m_data[0];
        }
        void push(const T& value) {
            m_data.push_back(value);
            m_map[value] = m_data.size() - 1;
            heapify_up(m_data.size() - 1);
        }
        T pop() {
            T value; 
            value = m_data[0];
            delete_node(0);
            return value;
        }
        void delete_node(size_t index) {
            if(!has_child(index)) {
                m_map.erase(m_data[index]);
                m_data.erase(m_data.begin() + index);
            }
            else {
                swap(index, m_data.size() - 1);
                m_map.erase(m_data[m_data.size() - 1]);
                m_data.pop_back();
                heapify_down(index);
            }
        }
        void replace(size_t index, const T& value) {
            if(value == m_data[index])
                return;
            if(m_comp(value, m_data[index])) {
                set_data(index, value);
                heapify_up(index);
            } else {
                set_data(index, value);
                heapify_down(index);
            }
        }
        void clear() {
            m_data.clear();
            m_map.clear();
        }
        // TODO: Too specific to T type allowing `-int`
        // Also I assume that the heap is a min binary heap.
        // I allow myself this implementation because it's only
        // used in Dijkstra's algorithm.
        void decrease_key(T key, int value) {
            m_data[m_map[key]] -= value;
            heapify_up(m_map[key]);
        }

        // Inspection
        size_t size() const {
            return m_data.size();
        }
        bool empty() const {
            return m_data.empty();
        }
        const T& left_child(size_t index) const {
            return m_data[left_child_index(index)];
        }
        const T& right_child(size_t index) const {
            return m_data[right_child_index(index)];
        }
        const T& parent(size_t index) const {
            return m_data[parent_index(index)];
        }
        int get_height() const {
            return ceil(log2(m_data.size() + 1)) - 1;
        }
        bool has_left_child(size_t index) const {
            return left_child_index(index) < m_data.size();
        }
        bool has_right_child(size_t index) const {
            return right_child_index(index) < m_data.size();
        }
        bool has_parent(size_t index) const {
            return index != 0;
        };
        bool has_child(size_t index) const {
            return has_left_child(index) || has_right_child(index);
        }
        const std::vector<T>& get_vector() const {
            return m_data;
        }
        const std::map<T,size_t>& get_map() const {
            return m_map;
        }

        friend std::ostream& operator<<(std::ostream& out, const BinaryHeap<T, Compare>& heap) {
            if(!heap.empty()) {
                out << '[';
                std::copy (heap.m_data.begin(), heap.m_data.end(), std::ostream_iterator<T>(out, ", "));
                out << "\b\b]";
            }
            return out;
        }


    protected:

        // Internal
        void swap(size_t index1, size_t index2) {
            m_map[m_data[index1]] = index2;
            m_map[m_data[index2]] = index1;
            std::iter_swap(m_data.begin() + index1, m_data.begin() + index2);
        }
        // Could by optimized
        void set_data(const std::vector<T>& data) {
            m_data = data;
            m_map.clear();
            for(int i = 0; i < m_data.size(); i++) {
                m_map[m_data[i]] = i;
            }
            for(int i = m_data.size() / 2 - 1; i >= 0; i--) {
                heapify_down(i);
            }
        }
        void set_data(size_t index, const T& d) {
            m_map.erase(m_data[index]);
            m_data[index] = d;
            m_map[d] = index;
        }
        void heapify_up(size_t index) {
            int p_index = parent_index(index);
            while(p_index >= 0 && m_comp(m_data[index], m_data[p_index])) {
                swap(index, p_index);
                index = p_index;
                p_index = parent_index(index);
            }
        }
        void heapify_down(size_t index) { 
            int left_index = left_child_index(index);
            while(left_index < m_data.size()) {
                int current_index = left_index;
                int right_index = right_child_index(index);
                if(right_index < m_data.size() && m_comp(m_data[right_index], m_data[left_index])) {
                    current_index = right_index;
                }
                if(m_comp(m_data[current_index], m_data[index])) {
                    swap(index, current_index);
                }
                else {
                    break;
                }
                index = current_index;
                left_index = left_child_index(current_index);
            }
        }
};

#endif // HEAP_H
