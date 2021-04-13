#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "node.hpp"

// Depth-first search traversals
template<typename T>
void inorder_rec(Node<T>* root, std::vector<T>& order) {
    if(root->left)
        inorder_rec(root->left, order);
    order.push_back(root->value);
    if(root->right)
        inorder_rec(root->right, order);
}

template<typename T>
void preorder_rec(Node<T>* root, std::vector<T>& order) {
    order.push_back(root->value);
    if(root->left)
        preorder_rec(root->left, order);
    if(root->right)
        preorder_rec(root->right, order);
}

template<typename T>
void postorder_rec(Node<T>* root, std::vector<T>& order) {
    if(root->left)
        postorder_rec(root->left, order);
    if(root->right)
        postorder_rec(root->right, order);
    order.push_back(root->value);
}

template<typename T>
void revinorder_rec(Node<T>* root, std::vector<T>& order) {
    if(root->right)
        revinorder_rec(root->right, order);
    order.push_back(root->value);
    if(root->left)
        revinorder_rec(root->left, order);
}

template<typename T>
std::vector<T> inorder_it(Node<T>* root) {
    std::vector<T> order;
    std::stack<Node<T>*> s;
    Node<T>* current = root;
    while(!s.empty() || current) {
        if(current) {
            s.push(current);
            current = current->left;
        }
        else {
            current = s.top(); s.pop();
            order.push_back(current->value);
            current = current->right;
        }
    }
    return order;
}

template<typename T>
std::vector<T> preorder_it(Node<T>* root) {
    std::vector<T> order;
    std::stack<Node<T>*> s;
    Node<T>* current = root;
    while(!s.empty() || current) {
        if(current) {
            order.push_back(current->value);
            s.push(current);
            current = current->left;
        }
        else {
            current = s.top(); s.pop();
            current = current->right;
        }
    }
    return order;
}

template<typename T>
std::vector<T> postorder_it(Node<T>* root) {
    std::vector<T> order;
    std::stack<Node<T>*> s;
    Node<T>* current = root;
    Node<T>* last_visited = nullptr;
    while(!s.empty() || current) {
        if(current) {
            s.push(current);
            current = current->left;
        }
        else {
            Node<T>* temp = s.top();
            if(temp->right && temp->right != last_visited)
                current = temp->right;
            else {
                order.push_back(temp->value);
                last_visited = s.top();
                s.pop();
            }
        }
    }
    return order;
}

template<typename T>
std::vector<T> revinorder_it(Node<T>* root) {
    std::vector<T> order;
    std::stack<Node<T>*> s;
    Node<T>* current = root;
    while(!s.empty() || current) {
        if(current) {
            s.push(current);
            current = current->right;
        }
        else {
            current = s.top(); s.pop();
            order.push_back(current->value);
            current = current->left;
        }
    }
    return order;
}

// Breadth-first search traversal (adapted to rooted binary tree)
template<typename T>
std::vector<T> bfs(Node<T>* root) {
    std::queue<Node<T>*> q;
    std::vector<T> order({root->value});
    q.push(root);
    while(!q.empty()) {
        Node<T>* current = q.front(); q.pop();
        if(current->left) {
            order.push_back(current->left->value);
            q.push(current->left);
        }
        if(current->right) {
            order.push_back(current->right->value);
            q.push(current->right);
        }
    }
    return order;
}


#endif // TREE_TRAVERSAL_H
