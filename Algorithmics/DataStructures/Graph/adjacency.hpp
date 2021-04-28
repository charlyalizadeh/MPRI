/*
 * TODO: Write my own implementation of `matrix` and use it in this class
 */
#ifndef ADJACENCY_H
#define ADJACENCY_H

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>
#include <string>
#include <climits>
#include "../Heap/heap.hpp"
#include "../Heap/print_heap.hpp"
#include "dijkstranode.hpp"



using namespace boost::numeric::ublas;



// m is assumed to be squarred
void increase_dim(matrix<int> &m, int inc=1) {
    size_t old_size = m.size1();
    m.resize(old_size + inc, old_size + inc);
    for(size_t i = old_size; i < m.size1(); i++) {
        for(size_t j = 0; j < m.size1(); j++) {
            m(i, j) = 0;
            m(j, i) = 0;
        }
    }
};




template<typename L = std::string>
class GraphAdjacency {
    private:
        matrix<int> adj;
        std::vector<L> label;

    public:

        GraphAdjacency(): adj({}) {};

        // Basic
        void add_edge(int src, int dst, double weight=1) {
            adj(src, dst) = weight;
            adj(dst, src) = weight;
            auto edges = get_edges();
        }
        void add_vertex() {
            increase_dim(adj);
            label.push_back(L());
        }
        bool has_edge(int src, int dst) {
            return adj(src, dst) != 0;
        }
        bool has_vertex(int vertex) {
            return adj.size1() > vertex;
        }
        size_t ne() {
            int ne = 0;
            for(size_t i = 0; i < adj.size1() - 1; i++)
                for(size_t j = i + 1; j < adj.size1(); j++)
                    ne += adj(i, j) != 0;
            return ne;
        }
        size_t nv() {
            return adj.size1();
        }
        L get_label(int vertex) {
            return label[vertex];
        }
        auto get_edges() {
            std::vector<std::pair<size_t,size_t>> edges;
            for(size_t i = 0; i < adj.size1() - 1; i++)
                for(size_t j = i + 1; j < adj.size1(); j++)
                    if(adj(i, j) != 0)
                        edges.push_back({i, j});
            return edges;
        }
        std::vector<size_t> neighbors(size_t v) {
            std::vector<size_t> neighbors;
            for(size_t n = 0; n < nv(); n++) {
                if(v != n && adj(v, n))
                    neighbors.push_back(n);
            }
            return neighbors;
        }

        // Shortest path
        auto dijkstra(size_t src) {
            std::vector<int> dists(nv(), INT_MAX);
            dists[src] = 0;
            std::vector<int> prevs(nv(), -1);
            std::vector<int> visited(nv(), false);
            auto heap = BinaryHeap<DijkstraNode, std::less<DijkstraNode>, DijkstraNodeCompare>();
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
};

#endif
