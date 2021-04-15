#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

template <typename T>
struct Node;

template <typename T>
int get_height(Node<T>* node);
template <typename T>
int get_value(Node<T>* node);
template<typename T>
int compute_height(Node<T>* node);
template<typename T>
int compute_balance(Node<T>* node);
template<typename T>
int get_balance(Node<T>* node);
template<typename T>
bool is_balanced(Node<T>* node);

template <typename T>
struct Node {
        T value;
        int height;
        Node<T>* left;
        Node<T>* right;

        Node(T value) : value(value), left(nullptr), right(nullptr), height(0) {}
        ~Node() {
            if(left) delete left;
            if(right) delete right;
        }

        Node<T>* find_min() {
            Node<T>* min_node = this;
            while(min_node->left != nullptr) {
                min_node = min_node->left;
            }
            return min_node;
        }
            
        Node<T>* find_max() {
            Node<T>* min_node = this;
            while(min_node->right != nullptr) {
                min_node = min_node->right;
            }
            return min_node;
        }

        void update_height() {
            height = 1 + std::max(get_height(right), get_height(left));
        }



        bool search(T s_value) {
            if(value == s_value)
                return true;
            else if(s_value > value) {
                if(right)
                    return right->search(s_value);
                else
                    return false;
            }
            else {
                if(left)
                    return left->search(s_value);
                else
                    return false;
            }
        }

        // Depth-first search traversals
        void inorder_rec(std::vector<T>& order) {
            if(left)
                left->inorder_rec(order);
            order.push_back(value);
            if(right)
                right->inorder_rec(order);
        }

        void preorder_rec(std::vector<T>& order) {
            order.push_back(value);
            if(left)
                left->preorder_rec(order);
            if(right)
                right->preorder_rec(order);
        }

        void postorder_rec(std::vector<T>& order) {
            if(left)
                left->postorder_rec(order);
            if(right)
                right->postorder_rec(order);
            order.push_back(value);
        }

        void revinorder_rec(std::vector<T>& order) {
            if(right)
                right->revinorder_rec(order);
            order.push_back(value);
            if(left)
                left->revinorder_rec(order);
        }

        std::vector<T> inorder_it() {
            std::vector<T> order;
            std::stack<Node<T>*> s;
            Node<T>* current = this;
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

        std::vector<T> preorder_it() {
            std::vector<T> order;
            std::stack<Node<T>*> s;
            Node<T>* current = this;
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

        std::vector<T> postorder_it() {
            std::vector<T> order;
            std::stack<Node<T>*> s;
            Node<T>* current = this;
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

        std::vector<T> revinorder_it() {
            std::vector<T> order;
            std::stack<Node<T>*> s;
            Node<T>* current = this;
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
        std::vector<T> bfs() {
            std::queue<Node<T>*> q;
            std::vector<T> order({value});
            q.push(this);
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
};


template<typename T>
int get_height(Node<T>* node) {
    return node ? node->height : -1;
}
template<typename T>
int compute_height(Node<T>* node) {
    if(!node)
        return -1;
    else
        return 1 + std::max(compute_height(node->left), compute_height(node->right));
}
template<typename T>
int compute_balance(Node<T>* node) {
    if(!node)
        return 0;
    else
        return compute_height(node->right) - compute_height(node->left);
}
template<typename T>
int get_balance(Node<T>* node) {
    if(!node)
        return 0;
    else
        return get_height(node->right) - get_height(node->left);
}
template<typename T>
bool is_balanced(Node<T>* node) {
    return !node ||
           (is_balanced(node->left) &&
            is_balanced(node->right) &&
            abs(compute_balance(node)) <= 1);
}
#endif


