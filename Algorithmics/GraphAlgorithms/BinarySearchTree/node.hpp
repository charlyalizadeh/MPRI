#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
struct Node {
        T value;
        Node<T>* left;
        Node<T>* right;

        Node(T value) : value(value) {
            left = nullptr;
            right = nullptr;
        };
        ~Node() {
            if(left) delete left;
            if(right) delete right;
        };
};

#endif
