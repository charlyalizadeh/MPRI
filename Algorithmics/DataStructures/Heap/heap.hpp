#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cmath>


int left_child_index(size_t index) {
    return 2 * index + 1;
}
int right_child_index(size_t index) {
    return 2 * index + 2;
}
int parent_index(size_t index) {
    return (index - 1) / 2;
}

template <typename T>
class MaxBinaryHeap {
    private:
        std::vector<T> m_data;

    public:

        // Creation
        MaxBinaryHeap(std::vector<T>& data): m_data(data) { 
            for(int i = m_data.size() / 2 - 1; i >= 0; i--) {
                heapify_down(i);
            }
        }
        MaxBinaryHeap(): m_data({}) { }
        MaxBinaryHeap<T> merge(const MaxBinaryHeap<T>& other) const {
            auto merged_data = std::vector<T>();
            merged_data.insert(merged_data.end(), m_data.begin(), m_data.end());
            merged_data.insert(merged_data.end(), other.m_data.begin(), other.m_data.end());
            return MaxBinaryHeap<T>(merged_data);
        }
        void meld(MaxBinaryHeap<T>& other) {
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
                m_data.erase(m_data.begin() + index);
            }
            else {
                swap(index, m_data.size() - 1);
                m_data.pop_back();
                heapify_down(index);
            }
        }
        void replace(size_t index, const T& value) {
            if(value == m_data[index])
                return;
            if(value > m_data[index]) {
                m_data[index] = value;
                heapify_up(index);
            } else {
                m_data[index] = value;
                heapify_down(index);
            }
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
        }
        bool has_child(size_t index) const {
            return has_left_child(index) || has_right_child(index);
        }
        const std::vector<T>& get_vector() const {
            return m_data;
        }

        friend std::ostream& operator<<(std::ostream& out, const MaxBinaryHeap<T>& heap) {
            if(!heap.empty()) {
                out << '[';
                std::copy (heap.m_data.begin(), heap.m_data.end(), std::ostream_iterator<T>(out, ", "));
                out << "\b\b]";
            }
            return out;
        }


    private:


        // Internal
        void swap(size_t index1, size_t index2) {
            std::iter_swap(m_data.begin() + index1, m_data.begin() + index2);
        }
        void set_node(size_t index, const T& value) {
            if(value == m_data[index]) {
                return;
            }
            bool is_bigger = value > m_data[index];
            m_data[index] = value;
            if(is_bigger)
                heapify_up(index);
            else
                heapify_down(index);
        }
        void heapify_up(size_t index) {
            int p_index = parent_index(index);
            while(p_index >= 0 && m_data[p_index] < m_data[index]) {
                swap(index, p_index);
                index = p_index;
                p_index = parent_index(index);
            }
        }
        void heapify_down(size_t index) { 
            int left_index = left_child_index(index);
            while(left_index < m_data.size()) {
                int bigger_index = left_index;
                int right_index = right_child_index(index);
                if(right_index < m_data.size() && m_data[right_index] > m_data[left_index]) {
                    bigger_index = right_index;
                }
                if(m_data[index] < m_data[bigger_index]) {
                    swap(index, bigger_index);
                }
                else {
                    break;
                }
                index = bigger_index;
                left_index = left_child_index(bigger_index);
            }
        }
};

#endif // HEAP_H
