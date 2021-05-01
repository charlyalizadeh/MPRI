#ifndef ASTARTNODE_H
#define ASTARTNODE_H

#include <string>
#include <map>
#include <algorithm>
#include "../Heap/heapmap.hpp"


struct AstarNode {
    int v;
    int h;
    int g;

    AstarNode(): v(0), h(0), g(0) {}
    AstarNode(int v, int h=0, int g=0): v(v), h(h), g(g) {}

    operator std::string() const {
        return "(" + std::to_string(h) + "," + std::to_string(g) + ")";
    }

    void set_costs(int new_g, int new_h) {
        g = new_g;
        h = new_h;
    }
};

struct AstarNodeCompare {
    bool operator() (const AstarNode& lhs, const AstarNode& rhs) const {
        return lhs.v < rhs.v;
    }
};
inline bool operator<(const AstarNode& lhs, const AstarNode& rhs) {
    return lhs.g + lhs.h < rhs.g + rhs.h;
}
inline bool operator>(const AstarNode& lhs, const AstarNode& rhs) {
    return lhs.g + lhs.h > rhs.g + rhs.h;
}
inline bool operator==(const AstarNode& lhs, int rhs) {
    return lhs.v == rhs;
}
inline bool operator==(int lhs, const AstarNode& rhs) {
    return lhs == rhs.v;
}
inline bool operator==(const AstarNode& lhs, const AstarNode& rhs) {
    return lhs.v == rhs.v;
}


template <typename T, typename Compare = std::less<T>, typename CompareMap = std::less<T>>
class AstarBinaryHeap: public BinaryHeapMapped<T,Compare,CompareMap> {
    public:
        bool has_key(const T& key) const {
            return std::find(this->m_data.begin(), this->m_data.end(), key) != this->m_data.end();
        }
        void set_costs(T key, int g, int h) {
            this->m_data[this->m_map[key]].set_costs(g, h);
        }
};

#endif
