#include <cxxtest/TestSuite.h>
#include <vector>
#include "../heap.hpp"

class BinaryHeapTest: public CxxTest::TestSuite {
    public:
        void test_constructors() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({4, 2, 3, 1}));
        }
        void test_merge() {
            std::vector<int> data1({0, 4, 6, 8});
            std::vector<int> data2({1, 3, 5, 7});
            auto heap1 = BinaryHeap<int>(data1);
            auto heap2 = BinaryHeap<int>(data2);
            auto merged_heap = BinaryHeap<int>();
            heap1.merge(heap2, merged_heap);
            TS_ASSERT_EQUALS(merged_heap.get_vector(), std::vector<int>({8, 7, 6, 1, 4, 3, 5, 0}));
        }
        void test_meld() {
            std::vector<int> data1({0, 4, 6, 8});
            std::vector<int> data2({1, 3, 5, 7});
            auto heap1 = BinaryHeap<int>(data1);
            auto heap2 = BinaryHeap<int>(data2);
            heap1.meld(heap2);
            TS_ASSERT_EQUALS(heap1.get_vector(), std::vector<int>({8, 7, 6, 1, 4, 3, 5, 0}));
        }
        void test_peek() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.peek(), 4);
        }
        void test_pop() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.pop(), 4);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({3, 2, 1}));
        }
        void test_delete_node() {
            std::vector<int> data({6, 5, 4, 3, 2, 1});
            auto heap = BinaryHeap<int>(data);
            heap.delete_node(1);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({6, 3, 4, 1, 2}));
        }
        void test_replace() {
            std::vector<int> data({6, 5, 4, 3, 2, 1});
            auto heap = BinaryHeap<int>(data);
            heap.replace(0, 0);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({5, 3, 4, 0, 2, 1}))
        }
        void test_size() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.size(), 4);
        }
        void test_empty() {
            auto heap_empty = BinaryHeap<int>();
            TS_ASSERT(heap_empty.empty());
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT(!heap.empty());
        }
        void test_left_child() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.left_child(0), 2);
            TS_ASSERT_EQUALS(heap.left_child(1), 1);
        }
        void test_right_child() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.right_child(0), 3);
        }
        void test_parent() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.parent(1), 4);
            TS_ASSERT_EQUALS(heap.parent(2), 4);
            TS_ASSERT_EQUALS(heap.parent(3), 2);
        }
        void test_get_height() {
            std::vector<int> data({1, 2, 3});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.get_height(), 1);
            heap.push(4);
            TS_ASSERT_EQUALS(heap.get_height(), 2);
        }
        void test_has_left_child() {
            std::vector<int> data({1, 2, 3});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT(heap.has_left_child(0));
            TS_ASSERT(!heap.has_left_child(1));
            heap.push(4);
            TS_ASSERT(heap.has_left_child(1));
        }
        void test_has_right_child() {
            std::vector<int> data({1, 2, 3});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT(heap.has_right_child(0));
            TS_ASSERT(!heap.has_right_child(1));
            heap.push(4); heap.push(5);
            TS_ASSERT(heap.has_right_child(1));
        }
        void test_has_parent() {
            std::vector<int> data({1, 2, 3});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT(!heap.has_parent(0));
            TS_ASSERT(heap.has_parent(1));
        }
        void test_has_child() {
            std::vector<int> data({1, 2, 3});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT(heap.has_child(0));
            TS_ASSERT(!heap.has_child(1));
            heap.push(4);
            TS_ASSERT(heap.has_child(1));
        }
        void test_get_vector() {
            std::vector<int> data({1, 2, 3});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({3, 2, 1}));
        }
};
