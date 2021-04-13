#ifndef TREE_BST_H
#define TREE_BST_H

#include <vector>
#include "node.hpp"


template<typename T>
Node<T>* find_min(Node<T>* root) {
    Node<T>* min_node = root;
    while(min_node->left != nullptr) {
        min_node = min_node->left;
    }
    return min_node;
}

template<typename T>
Node<T>* find_max(Node<T>* root) {
    Node<T>* min_node = root;
    while(min_node->right != nullptr) {
        min_node = min_node->right;
    }
    return min_node;
}

template <typename T>
void insertBST(Node<T>* root, T value, bool valid_equal=true) {
    if(!valid_equal && value == root->value)
        return;
    if(value > root->value) {
        if(root->right)
            insertBST(root->right, value, valid_equal);
        else
            root->right = new Node<T>(value);
    }
    else {
        if(root->left)
            insertBST(root->left, value, valid_equal);
        else
            root->left = new Node<T>(value);

    }
}

template<typename T>
Node<T>* buildBST(std::vector<T> values) {
    if(values.empty())
        return nullptr;
    Node<T>* root = new Node<T>(values[0]);
    for(size_t i = 1; i < values.size(); i++)
        insertBST(root, values[i]);
    return root;
}

template <typename T>
bool searchBST(Node<T>* root, T value) {
    if(!root)
        return false;
    else
        if(value == root->value)
            return true;
        else if(value > root->value)
            return searchBST(root->right, value);
        else
            return searchBST(root->left, value);
}

template<typename T>
Node<T>* deleteBST(Node<T>* root, T value) {
    if(!root)
        return root;
    if(value > root->value)
        root->right = deleteBST(root->right, value);
    else if(value < root->value)
        root->left = deleteBST(root->left, value);
    else {
        if(!(root->right)) {
            return root->left;
        }
        if(!(root->left)) {
            return root->right;
        }
        Node<T>* min_node = find_min(root->right);
        root->value = min_node->value;
        root->right = deleteBST(root->right, min_node->value);
    }
    return root;
}


#endif // TREE_BST_H
