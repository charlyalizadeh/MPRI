#ifndef DIJKSTRANODE_H
#define DIJKSTRANODE_H

#include <string>
#include <map>
#include "../Heap/heapmap.hpp"


struct DijkstraNode {
    int v;
    int dist;

    DijkstraNode(int v=0, int dist=0): v(v), dist(dist) {}

    void set_dist(int value) {
        dist = value;
    }

    DijkstraNode& operator-=(int value) {
        dist -= value;
        return *this;
    }
    DijkstraNode operator-(int value) {
        return DijkstraNode(v, dist - value);
    }
    operator std::string() const {
        return "(" + std::to_string(v) + "," + std::to_string(dist) + ")";
    }
};

struct DijkstraNodeCompare {
    bool operator() (const DijkstraNode& lhs, const DijkstraNode& rhs) const {
        return lhs.v < rhs.v;
    }
};
inline bool operator<(const DijkstraNode& lhs, const DijkstraNode& rhs) {
    return lhs.dist < rhs.dist;
}
inline bool operator>(const DijkstraNode& lhs, const DijkstraNode& rhs) {
    return lhs.dist > rhs.dist;
}
inline bool operator==(const DijkstraNode& lhs, int rhs) {
    return lhs.v == rhs;
}
inline bool operator==(int lhs, const DijkstraNode& rhs) {
    return lhs == rhs.v;
}
inline bool operator==(const DijkstraNode& lhs, const DijkstraNode& rhs) {
    return lhs.v == rhs.v;
}

template <typename T, typename Compare = std::less<T>, typename CompareMap = std::less<T>>
class DijkstraBinaryHeap: public BinaryHeapMapped<T,Compare,CompareMap> {
    public:
        // TODO: Too specific to T type allowing `-int`
        // Also I assume that the heap is a min binary heap.
        // I allow myself this implementation because it's only
        // used in Dijkstra's algorithm.
        void decrease_key(T key, int value) {
            this->m_data[this->m_map[key]] -= value;
            this->heapify_up(this->m_map[key]);
        }
};


#endif
