/*
 * TODO: Write my own implementation of `matrix` and use it in this class
 */
#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>
#include <string>
#include <climits>
#include "dijkstranode.hpp"
#include "astarnode.hpp"


using namespace boost::numeric::ublas;



// m is assumed to be squarred
inline void increase_dim(matrix<int> &m, int inc=1) {
    size_t old_size = m.size1();
    m.resize(old_size + inc, old_size + inc);
    for(size_t i = old_size; i < m.size1(); i++) {
        for(size_t j = 0; j < m.size1(); j++) {
            m(i, j) = 0;
            m(j, i) = 0;
        }
    }
};

inline std::vector<int> construct_path(std::vector<int> prevs, int current) {
    std::vector<int> path;
    while(current != -1) {
        path.push_back(current);
        current = prevs[current];
    }
    return path;
}


template<typename L = std::string>
class GraphMatrix {
    private:
        matrix<int> adj;
        std::vector<L> label;

    public:

        GraphMatrix(int n = 0): adj(matrix<int>(n, n)), label(std::vector<L>(n, L())) {};

        // Basic
        void add_vertex() {
            increase_dim(adj);
            label.push_back(L());
        }
        void add_edge(int src, int dst, double weight=1) {
            adj(src, dst) = weight;
            adj(dst, src) = weight;
        }
        void add_vertices(int n) {
            increase_dim(adj, n);
            std::vector<L> new_label(n, L());
            label.insert(end(label), begin(new_label), end(new_label));
        }
        void delete_edge(int src, int dst) {
            adj(src, dst) = 0;
            adj(dst, src) = 0;
        }
        void delete_all_edges(int v) {
            for(size_t n = 0; n < nv(); n++) {
                delete_edge(v, n);
            }
        }
        bool has_vertex(int vertex) const {
            return adj.size1() > vertex;
        }
        bool has_edge(int src, int dst) const {
            return adj(src, dst) != 0;
        }
        size_t nv() const {
            return adj.size1();
        }
        size_t ne() const {
            int ne = 0;
            for(size_t i = 0; i < adj.size1() - 1; i++)
                for(size_t j = i + 1; j < adj.size1(); j++)
                    ne += adj(i, j) != 0;
            return ne;
        }
        L get_label(int vertex)  const {
            return label[vertex];
        }
        auto get_edges() const {
            std::vector<std::pair<size_t,size_t>> edges;
            for(size_t i = 0; i < adj.size1() - 1; i++)
                for(size_t j = i + 1; j < adj.size1(); j++)
                    if(adj(i, j) != 0)
                        edges.push_back({i, j});
            return edges;
        }
        std::vector<size_t> neighbors(size_t v) const {
            std::vector<size_t> neighbors;
            for(size_t n = 0; n < nv(); n++) {
                if(v != n && adj(v, n))
                    neighbors.push_back(n);
            }
            return neighbors;
        }

        // Shortest path
        auto dijkstra(size_t src) const {
            std::vector<int> dists(nv(), INT_MAX);
            dists[src] = 0;
            std::vector<int> prevs(nv(), -1);
            std::vector<int> visited(nv(), false);
            auto heap = DijkstraBinaryHeap<DijkstraNode, std::less<DijkstraNode>, DijkstraNodeCompare>();
            for(size_t v = 0; v < nv(); v++) {
                heap.push(DijkstraNode(v, dists[v]));
            }
            while(!heap.empty()) {
                auto current = heap.pop();
                visited[current.v] = true;
                for(auto const& n: neighbors(current.v)) {
                    if(visited[n])
                        continue;
                    int alt = dists[current.v] + adj(current.v, n);
                    if(alt < dists[n]) {
                        prevs[n] = current.v;
                        heap.decrease_key(DijkstraNode(n, dists[n]), dists[n] - alt);
                        dists[n] = alt;
                    }
                }
            }
            return std::pair<std::vector<int>, std::vector<int>>({dists, prevs});
        }
        // TODO: Generalize this function to accept custom heuristics.
        // Currently the heuristic is the distance in the adjacency matrix
        auto astar(size_t src, size_t dst) const {
            std::vector<int> prevs(nv(), -1);
            auto heap = AstarBinaryHeap<AstarNode, std::less<AstarNode>>();
            heap.push(AstarNode(src));
            std::vector<int> g_scores(nv(), INT_MAX);
            std::vector<int> f_scores(nv(), INT_MAX);
            g_scores[src] = 0;
            f_scores[src] = adj(src, dst);
            while(!heap.empty()) {
                auto current = heap.pop();
                if(current.v == dst) {
                    return construct_path(prevs, current.v);
                }
                for(auto const& n: neighbors(current.v)) {
                    int tentative_score = current.g + adj(current.v, n);
                    if(tentative_score < g_scores[n]) {
                        prevs[n] = current.v;
                        g_scores[n] = tentative_score;
                        f_scores[n] = tentative_score + adj(n, dst);
                        if(!heap.has_key(AstarNode(n))) {
                            heap.push(AstarNode(n, g_scores[n], f_scores[n]));
                        }
                    }
                }
            }
            return std::vector<int>();
        }
};

#endif
