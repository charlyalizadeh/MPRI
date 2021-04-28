# Graph

**Definition**: A **graph** G is a triple consisting of a **vertex set** V(G), an **edge set** E(G), and a relation that associates with each edge two vertices (not necessarily distinct) called its **endpoints**. [[1]](#1)  

A graph data structure is usually implemented using either a matrix (called an ***adjacency matrix***) or a linked list (called an ***adjacency list***). The implementation depends on the use case of the graph, some algorithms will perform better on an adjacency matrix than on a adjacency list and vice versa.

|               | Adjacency Matrix | Adjacency List   |
|---------------|------------------|------------------|
| Storage       | O(\|V\|^2)       | O(\|V\|+\|E\|)   |
| Add vertex    | O(\|V\|^2)       | O(1)             |
| Add edge      | O(1)             | O(1)             |
| Delete vertex | O(\|V\|^2)       | O(\|V\| + \|E\|) |
| Delete edge   | O(1)             | O(\|E\|)         |

# Implementation

*  Adjacency matrix [`graphmatrix.hpp`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp)
    * Basic
        * [X] Add vertex [`add_vertex`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L45)
        * [X] Add edge [`add_edge`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L49)
        * [X] Has vertex [`has_vertex`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L54)
        * [X] Has edge [`has_edge`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L57)
        * [X] Number of vertices [`nv`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L60)
        * [X] Number of edges [`ne`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L63)
        * [X] Get the label of a vertex [`get_label`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L70)
        * [X] Get all edges [`get_edges`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L73)
        * [X] Get the neighbors of a vertex [`neighbors`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L81)
    * Path
        * [X] Dijkstra [`dijkstra`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L91)
        * [ ] A*
        * [ ] Bellman-For
    * Traversal/Ordering
        * [ ] Breadth First Search
        * [ ] Depth First Search
    * Minimum Spanning Tree
        * [ ] Kruskal
        * [ ] Prim
    * Chordal Extension (go see [Triangulation.jl](https://github.com/charlyalizadeh/Triangulation.jl) for an implementation of those algorithms in [Julia](https://julialang.org/), I may not have the time to reimplement them in C++)
        * [ ] Elimination Game
        * [ ] Minimum Degree
        * [ ] Cholesky
        * [ ] LEX-M
        * [ ] SMS
        * [ ] MCS-M
        * [ ] CliqueMinTriang
        * [ ] MinTriang


# References

<a id="1">[1]</a> D. B. West. *Graph Theory: Introduction to, Second Edition.* Prentice Hall, 2001.
