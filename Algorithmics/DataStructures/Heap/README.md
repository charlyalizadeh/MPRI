# Heap

A heap is tree-based data structure which ensure the following property:
* In a max heap (resp. min heap) for every node C admitting a parent P, the value of P is greater than (resp. lower than) or equal to the value of C.
* A heap is complete tree

## Implementation

Although a heap is a tree-based data structure the most efficient implementation uses arrays. The index of a node in the array corresponds to its index in a breadth-first search ordering of the tree.
For a breadth first search ordering of a complete binary we can make the following observation for a node of index `n`:
* The index of the parent (if exists) of `n` is `(n - 1) / 2`
* The index of the left child (if exists) of `n` is `2 * n + 2`
* The index of the right child (if exists) of `n` is `1 * n + 1`

The `BinaryHeap` class also contains a hashmap wich maps every key to its index in the array. This map is used for the Dijkstra's algorithm (see [`dijkstra`](https://github.com/charlyalizadeh/MPRI_prerequisite/blob/master/Algorithmics/DataStructures/Graph/graphmatrix.hpp#L91)) of the [Graph](https://github.com/charlyalizadeh/MPRI_prerequisite/tree/master/Algorithmics/DataStructures/Graph) data structure.
