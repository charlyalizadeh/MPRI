#ifndef BINARYHEAPMAPPED_H
#define BINARYHEAPMAPPED_H

#include <map>
#include "heap.hpp"


// TODO: Access field with get/set function instead of `this->`

template <typename T, typename Compare = std::greater<T>, typename CompareMap = std::less<T>>
class BinaryHeapMapped: public BinaryHeap<T, Compare> {
    protected:
        std::map<T, size_t, CompareMap> m_map;

    public:

        // Creation
        BinaryHeapMapped(Compare comp = Compare()):  BinaryHeap<T, Compare>(comp), m_map() { }
        BinaryHeapMapped(std::vector<T>& data, Compare comp = Compare()): BinaryHeap<T, Compare>(data, comp) { 
            for(int i = 0; i < this->m_data.size(); i++) {
                m_map[this->m_data[i]] = i;
            }
        }

        // Basic
        void push(const T& value) {
            m_map[value] = this->m_data.size();
            BinaryHeap<T, Compare>::push(value);
        }
        void delete_node(size_t index) {
            if(!this->has_child(index)) {
                m_map.erase(this->m_data[index]);
                this->m_data.erase(this->m_data.begin() + index);
            }
            else {
                swap(index, this->m_data.size() - 1);
                m_map.erase(this->m_data[this->m_data.size() - 1]);
                this->m_data.pop_back();
                this->heapify_down(index);
            }
        }
        void clear() {
            BinaryHeap<T, Compare>::clear();
            m_map.clear();
        }

        // Inspection
        const std::map<T,size_t>& get_map() const {
            return m_map;
        }


    protected:

        // Internal
        void swap(size_t index1, size_t index2) {
            m_map[this->m_data[index1]] = index2;
            m_map[this->m_data[index2]] = index1;
            std::iter_swap(this->m_data.begin() + index1, this->m_data.begin() + index2);
        }
        // Could by optimized
        void set_data(const std::vector<T>& data) {
            this->m_data = data;
            m_map.clear();
            for(int i = 0; i < this->m_data.size(); i++) {
                m_map[this->m_data[i]] = i;
            }
            for(int i = this->m_data.size() / 2 - 1; i >= 0; i--) {
                this->heapify_down(i);
            }
        }
        void set_data(size_t index, const T& d) {
            m_map.erase(this->m_data[index]);
            this->m_data[index] = d;
            m_map[d] = index;
        }
};

#endif // BINARYHEAPMAPPED_H
