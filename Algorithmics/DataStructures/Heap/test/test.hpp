#include <cxxtest/TestSuite.h>
#include <vector>
#include "../heap.hpp"
#include "../heapmap.hpp"

// Max Binary Heap test
class MaxBinaryHeapTest: public CxxTest::TestSuite {
    public:
        void test_constructors() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeapMapped<int>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({4, 2, 3, 1}));
            auto imap = std::map<int,size_t>{{4,0}, {2,1}, {3,2}, {1,3}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_merge() {
            std::vector<int> data1({0, 4, 6, 8});
            std::vector<int> data2({1, 3, 5, 7});
            auto heap1 = BinaryHeap<int>(data1);
            auto heap2 = BinaryHeap<int>(data2);
            auto merged_heap = BinaryHeapMapped<int>();
            heap1.merge(heap2, merged_heap);
            TS_ASSERT_EQUALS(merged_heap.get_vector(), std::vector<int>({8, 7, 6, 1, 4, 3, 5, 0}));
            auto imap = std::map<int,size_t>{{8,0}, {7,1}, {6,2}, {1,3}, {4,4}, {3,5}, {5,6}, {0,7}};
            TS_ASSERT_EQUALS(merged_heap.get_map(), imap);
        }
        void test_meld() {
            std::vector<int> data1({0, 4, 6, 8});
            std::vector<int> data2({1, 3, 5, 7});
            auto heap1 = BinaryHeapMapped<int>(data1);
            auto heap2 = BinaryHeapMapped<int>(data2);
            heap1.meld(heap2);
            TS_ASSERT_EQUALS(heap1.get_vector(), std::vector<int>({8, 7, 6, 1, 4, 3, 5, 0}));
            auto imap = std::map<int,size_t>{{8,0}, {7,1}, {6,2}, {1,3}, {4,4}, {3,5}, {5,6}, {0,7}};
            TS_ASSERT_EQUALS(heap1.get_map(), imap);
        }
        void test_peek() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeap<int>(data);
            TS_ASSERT_EQUALS(heap.peek(), 4);
        }
        void test_pop() {
            std::vector<int> data({1, 2, 3, 4});
            auto heap = BinaryHeapMapped<int>(data);
            TS_ASSERT_EQUALS(heap.pop(), 4);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({3, 2, 1}));
            auto imap = std::map<int,size_t>{{3, 0}, {2, 1}, {1, 2}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_delete_node() {
            std::vector<int> data({6, 5, 4, 3, 2, 1});
            auto heap = BinaryHeapMapped<int>(data);
            heap.delete_node(1);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({6, 3, 4, 1, 2}));
            auto imap = std::map<int,size_t>{{6, 0}, {3, 1}, {4, 2}, {1, 3}, {2, 4}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_replace() {
            std::vector<int> data({6, 5, 4, 3, 2, 1});
            auto heap = BinaryHeapMapped<int>(data);
            heap.replace(0, 0);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({5, 3, 4, 0, 2, 1}))
            auto imap = std::map<int,size_t>{{5, 0}, {3, 1}, {4, 2}, {0, 3}, {2, 4}, {1, 5}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
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
            auto heap = BinaryHeapMapped<int>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({3, 2, 1}));
            auto imap = std::map<int,size_t>{{3,0}, {2,1}, {1,2}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
};

// Min Binary Heap test
class MinBinaryHeapTest: public CxxTest::TestSuite {
    public:
        void test_constructors() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({1, 3, 2, 4}));
        }
        void test_merge() {
            std::vector<int> data1({8, 6, 4, 0});
            std::vector<int> data2({7, 5, 3, 1});
            auto heap1 = BinaryHeapMapped<int, std::less<int>>(data1);
            auto heap2 = BinaryHeapMapped<int, std::less<int>>(data2);
            auto merged_heap = BinaryHeapMapped<int, std::less<int>>();
            heap1.merge(heap2, merged_heap);
            TS_ASSERT_EQUALS(merged_heap.get_vector(), std::vector<int>({0, 1, 3, 7, 6, 5, 4, 8}));
            auto imap = std::map<int,size_t>{{0,0}, {1,1}, {3,2}, {7,3}, {6,4}, {5,5}, {4,6}, {8,7}};
            TS_ASSERT_EQUALS(merged_heap.get_map(), imap);
        }
        void test_meld() {
            std::vector<int> data1({8, 6, 4, 0});
            std::vector<int> data2({7, 5, 3, 1});
            auto heap1 = BinaryHeapMapped<int, std::less<int>>(data1);
            auto heap2 = BinaryHeapMapped<int, std::less<int>>(data2);
            heap1.meld(heap2);
            TS_ASSERT_EQUALS(heap1.get_vector(), std::vector<int>({0, 1, 3, 7, 6, 5, 4, 8}));
            auto imap = std::map<int,size_t>{{0,0}, {1,1}, {3,2}, {7,3}, {6,4}, {5,5}, {4,6}, {8,7}};
            TS_ASSERT_EQUALS(heap1.get_map(), imap);
        }
        void test_peek() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeapMapped<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.peek(), 1);
        }
        void test_pop() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeapMapped<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.pop(), 1);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({2, 3, 4}));
            auto imap = std::map<int,size_t>{{2,0}, {3,1}, {4,2}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_delete_node() {
            std::vector<int> data({1, 2, 3, 4, 5, 6});
            auto heap = BinaryHeapMapped<int, std::less<int>>(data);
            heap.delete_node(0);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({2, 4, 3, 6, 5}));
            auto imap = std::map<int,size_t>{{2,0}, {4,1}, {3,2}, {6,3}, {5,4}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_replace() {
            std::vector<int> data({1, 2, 3, 4, 5, 6});
            auto heap = BinaryHeapMapped<int, std::less<int>>(data);
            heap.replace(0, 7);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({2, 4, 3, 7, 5, 6}))
            auto imap = std::map<int,size_t>{{2,0}, {4,1}, {3,2}, {7,3}, {5,4}, {6,5}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_size() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeapMapped<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.size(), 4);
        }
        void test_empty() {
            auto heap_empty = BinaryHeap<int, std::less<int>>();
            TS_ASSERT(heap_empty.empty());
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeapMapped<int, std::less<int>>(data);
            TS_ASSERT(!heap.empty());
        }
        void test_left_child() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.left_child(0), 3);
            TS_ASSERT_EQUALS(heap.left_child(1), 4);
        }
        void test_right_child() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.right_child(0), 2);
        }
        void test_parent() {
            std::vector<int> data({4, 3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.parent(1), 1);
            TS_ASSERT_EQUALS(heap.parent(2), 1);
            TS_ASSERT_EQUALS(heap.parent(3), 3);
        }
        void test_get_height() {
            std::vector<int> data({3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.get_height(), 1);
            heap.push(0);
            TS_ASSERT_EQUALS(heap.get_height(), 2);
        }
        void test_has_left_child() {
            std::vector<int> data({3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT(heap.has_left_child(0));
            TS_ASSERT(!heap.has_left_child(1));
            heap.push(0);
            TS_ASSERT(heap.has_left_child(1));
        }
        void test_has_right_child() {
            std::vector<int> data({3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT(heap.has_right_child(0));
            TS_ASSERT(!heap.has_right_child(1));
            heap.push(0); heap.push(-1);
            TS_ASSERT(heap.has_right_child(1));
        }
        void test_has_parent() {
            std::vector<int> data({3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT(!heap.has_parent(0));
            TS_ASSERT(heap.has_parent(1));
        }
        void test_has_child() {
            std::vector<int> data({3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT(heap.has_child(0));
            TS_ASSERT(!heap.has_child(1));
            heap.push(0);
            TS_ASSERT(heap.has_child(1));
        }
        void test_get_vector() {
            std::vector<int> data({3, 2, 1});
            auto heap = BinaryHeap<int, std::less<int>>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<int>({1, 2, 3}));
        }
};

// More complexe structure test
struct Node {
    size_t v;
    int dist;

    Node(size_t v=0, int dist=0): v(v), dist(dist) {}

    void set_dist(int value) {
        dist = value;
    }

    Node& operator-=(int value) {
        dist -= value;
        return *this;
    }
    Node operator-(int value) {
        return Node(v, dist - value);
    }
    operator std::string() const {
        return "(" + std::to_string(v) + "," + std::to_string(dist) + ")";
    }
};


inline bool operator<(const Node& lhs, const Node& rhs) {
    return lhs.dist < rhs.dist;
}
inline bool operator>(const Node& lhs, const Node& rhs) {
    return lhs.dist > rhs.dist;
}
inline bool operator==(const Node& lhs, int rhs) {
    return lhs.v == rhs;
}
inline bool operator==(int lhs, const Node& rhs) {
    return lhs == rhs.v;
}
inline bool operator==(const Node& lhs, const Node& rhs) {
    return lhs.v == rhs.v;
}

class MinBinaryHeapNodeTest: public CxxTest::TestSuite {
    public:
        void test_constructors() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<Node>({{3,1}, {1,3}, {2,2}, {0,4}}));
        }
        void test_merge() {
            std::vector<Node> data1({{0,8}, {1,6}, {2,4}, {3,0}});
            std::vector<Node> data2({{4,7}, {5,5}, {6,3}, {7,1}});
            auto heap1 = BinaryHeapMapped<Node, std::less<Node>>(data1);
            auto heap2 = BinaryHeapMapped<Node, std::less<Node>>(data2);
            auto merged_heap = BinaryHeapMapped<Node, std::less<Node>>();
            heap1.merge(heap2, merged_heap);
            TS_ASSERT_EQUALS(merged_heap.get_vector(), std::vector<Node>({{3,0}, {7,1}, {6,3}, {4,7}, {1,6}, {5,5}, {2,4}, {0,8}}));
            auto imap = std::map<Node,size_t>{{{3,0},0}, {{7,1},1}, {{6,3},2}, {{4,7},3}, {{1,6},4}, {{5,5},5}, {{2,4},6}, {{0,8},7}};
            TS_ASSERT_EQUALS(merged_heap.get_map(), imap);
        }
        void test_meld() {
            std::vector<Node> data1({{0,8}, {1,6}, {2,4}, {3,0}});
            std::vector<Node> data2({{4,7}, {5,5}, {6,3}, {7,1}});
            auto heap1 = BinaryHeapMapped<Node, std::less<Node>>(data1);
            auto heap2 = BinaryHeapMapped<Node, std::less<Node>>(data2);
            heap1.meld(heap2);
            TS_ASSERT_EQUALS(heap1.get_vector(), std::vector<Node>({{3,0}, {7,1}, {6,3}, {4,7}, {1,6}, {5,5}, {2,4}, {0,8}}));
            auto imap = std::map<Node,size_t>{{{3,0},0}, {{7,1},1}, {{6,3},2}, {{4,7},3}, {{1,6},4}, {{5,5},5}, {{2,4},6}, {{0,8},7}};
            TS_ASSERT_EQUALS(heap1.get_map(), imap);
        }
        void test_peek() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.peek(), Node(3, 1));
        }
        void test_pop() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeapMapped<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.pop(), Node(3,1));
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<Node>({{2,2}, {1,3}, {0,4}}));
            auto imap = std::map<Node,size_t>{{{2,2},0}, {{1,3},1}, {{0,4},2}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_delete_node() {
            std::vector<Node> data({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}});
            auto heap = BinaryHeapMapped<Node, std::less<Node>>(data);
            heap.delete_node(0);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<Node>({{1,2}, {3,4}, {2,3}, {5,6}, {4,5}}));
            auto imap = std::map<Node,size_t>{{{1,2},0}, {{3,4},1}, {{2,3},2}, {{5,6},3}, {{4,5},4}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_replace() {
            std::vector<Node> data({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}});
            auto heap = BinaryHeapMapped<Node, std::less<Node>>(data);
            heap.replace(0, Node(6,7));
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<Node>({{1,2}, {3,4}, {2,3}, {6,7}, {4,5}, {5,6}}))
            auto imap = std::map<Node,size_t>{{{1,2},0}, {{3,4},1}, {{2,3},2}, {{6,7},3}, {{4,5},4}, {{5,6},5}};
            TS_ASSERT_EQUALS(heap.get_map(), imap);
        }
        void test_size() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.size(), 4);
        }
        void test_empty() {
            auto heap_empty = BinaryHeap<Node, std::less<Node>>();
            TS_ASSERT(heap_empty.empty());
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT(!heap.empty());
        }
        void test_left_child() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.left_child(0), Node(1,3));
            TS_ASSERT_EQUALS(heap.left_child(1), Node(0,4));
        }
        void test_right_child() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.right_child(0), Node(2,2));
        }
        void test_parent() {
            std::vector<Node> data({{0,4}, {1,3}, {2,2}, {3,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.parent(1), Node(3,1));
            TS_ASSERT_EQUALS(heap.parent(2), Node(3,1));
            TS_ASSERT_EQUALS(heap.parent(3), Node(1,3));
        }
        void test_get_height() {
            std::vector<Node> data({{0,3}, {1,2}, {2,3}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.get_height(), 1);
            heap.push(Node(3,0));
            TS_ASSERT_EQUALS(heap.get_height(), 2);
        }
        void test_has_left_child() {
            std::vector<Node> data({{0,3}, {1,2}, {2,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT(heap.has_left_child(0));
            TS_ASSERT(!heap.has_left_child(1));
            heap.push(Node(3,0));
            TS_ASSERT(heap.has_left_child(1));
        }
        void test_has_right_child() {
            std::vector<Node> data({{0,3}, {1,2}, {2,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT(heap.has_right_child(0));
            TS_ASSERT(!heap.has_right_child(1));
            heap.push(Node(3,0)); heap.push(Node(4,-1));
            TS_ASSERT(heap.has_right_child(1));
        }
        void test_has_parent() {
            std::vector<Node> data({{0,3}, {1,2}, {2,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT(!heap.has_parent(0));
            TS_ASSERT(heap.has_parent(1));
        }
        void test_has_child() {
            std::vector<Node> data({{0,3}, {1,2}, {2,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT(heap.has_child(0));
            TS_ASSERT(!heap.has_child(1));
            heap.push(Node(3,0));
            TS_ASSERT(heap.has_child(1));
        }
        void test_get_vector() {
            std::vector<Node> data({{0,3}, {1,2}, {2,1}});
            auto heap = BinaryHeap<Node, std::less<Node>>(data);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<Node>({{2,1}, {1,2}, {0,3}}));
        }
        void test_decrease_key() {
            std::vector<Node> data({{0,3}, {1,2}, {2,1}});
            auto heap = BinaryHeapMapped<Node, std::less<Node>>(data);
            heap.decrease_key(Node(0,3), 4);
            TS_ASSERT_EQUALS(heap.get_vector(), std::vector<Node>({{0,-1}, {1,2}, {2,1}}));
        }
};
