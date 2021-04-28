#ifndef DIJKSTRANODE_H
#define DIJKSTRANODE_H

#include <string>


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

#endif
