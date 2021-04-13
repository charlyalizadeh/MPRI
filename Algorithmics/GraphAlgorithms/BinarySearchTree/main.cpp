#include "bst.hpp"
#include "traversal.hpp"
#include <iostream>

template<typename T>
void print_vector(std::vector<T> vect) {
    for(auto const& v : vect) {
        std::cout << v << ",";
    }
    std::cout << std::endl;
}


int main() {
    Node<int> root(5);
    insertBST(&root, 4);
    insertBST(&root, 3);
    std::vector<int> order;
    inorder_rec(&root, order);
    print_vector(order);
    return 0;
}
