#ifndef TREE_AVL_H
#define TREE_AVL_H

#include <cmath>
#include <vector>
#include <iostream>
#include "node.hpp"


template<typename T>
Node<T>* right_rotate(Node<T>* node) {
    Node<T>* left = node->left;
    node->left = left->right;
    left->right = node;
    node->height = compute_height(node);
    left->height = compute_height(left);
    return left;
}

template<typename T>
Node<T>* left_rotate(Node<T>* node) {
    Node<T>* right = node->right;
    node->right = right->left;
    right->left = node;
    node->height = compute_height(node);
    right->height = compute_height(right);
    return right;
}
 
template<typename T>
Node<T>* right_left_rotate(Node<T>* node) {
    node->right = right_rotate(node->right);
    node = left_rotate(node);
    return node;
}

template<typename T>
Node<T>* left_right_rotate(Node<T>* node) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
}

template<typename T>
Node<T>* insertAVL(Node<T>* root, T value) {
    if(!root) {
        return new Node<T>(value);
    }
    if(value > root->value)
        root->right = insertAVL(root->right, value);
    else if(value < root->value)
        root->left = insertAVL(root->left, value);
    else
        return root;
    root->update_height();
    int balance = get_balance(root);
    if(balance > 1) {
        if(root->right->value < value) {
            return left_rotate(root);
        }
        else {
            return right_left_rotate(root);
        }
    }
    else if(balance < -1) {
        if(root->left->value > value)
            return right_rotate(root);
        else
            return left_right_rotate(root);
    }
    return root;
}

template<typename T>
Node<T>* buildAVL(std::vector<T> values) {
    if(values.empty())
        return nullptr;
    Node<T>* root = new Node<T>(values[0]);
    for(size_t i = 1; i < values.size(); i++)
        insertAVL(root, values[i]);
    return root;
}

template<typename T>
Node<T>* deleteAVL(Node<T>* root, T value) {
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
        Node<T>* min_node = root->right->find_min();
        root->value = min_node->value;
        root->right = deleteBST(root->right, min_node->value);
    }
    root->update_height();
    int balance = get_balance(root);
    if(balance < -1) {
        if(get_balance(root->left) < 0)
            return right_rotate(root);
        else
            return left_right_rotate(root);
    }
    else if(balance > 1) {
        if(get_balance(root->right) >= 0)
            return left_rotate(root);
        else
            return right_left_rotate(root);
    }
    return root;
}


#endif // TREE_AVL_H
