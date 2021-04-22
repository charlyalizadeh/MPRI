#ifndef PRINT_HEAP_H
#define PRINT_HEAP_H

#include <vector>
#include "heap.hpp"


int max_size(const std::vector<std::string>& strings) {
    int size = 0;
    for(const auto& str: strings) {
        if(str.size() > size) {
            size = str.size();
        }
    }
    return size;
}

int get_node_depth(size_t index) {
    int depth = 0;
    int sum = pow(2.0, depth);
    while(sum  - 1 < index) {
        depth++;
        sum += pow(2.0, depth);
    }
    return depth;
}

std::vector<int> get_bounds(size_t depth) {
    int min_bound = pow(2.0, depth) - 1;
    int max_bound = pow(2.0, depth + 1) - 2;
    return {min_bound, max_bound};
}

auto get_bounds_all(size_t stop) {
    auto bounds = std::vector<std::vector<int>>();
    for(int i = 0; i < stop; i++) {
        bounds.push_back(get_bounds(i));
    }
    return bounds;
}

std::pair<int, int> get_coord(int node_index, int display_width, std::vector<std::vector<int>> bounds, int str_size) {
    int node_depth = get_node_depth(node_index);
    int nb_node = pow(2.0, node_depth);
    int width_offset = display_width / ((nb_node + 1) + 0.5);
    int row_index = node_index - bounds[node_depth][0];
    int x = row_index * width_offset + 1 * width_offset - str_size / 2;
    int y = node_depth * 3;
    return {x, y};
}


// Only work if `T` overload `to_string`
// Also this could be a lot less uglier, I may take the time later to improve this method
template <typename T>
auto get_heap_tree_str(BinaryHeap<T> heap) {
    std::vector<std::string> data_str;
    for(auto const& d : heap.get_vector()) {
        data_str.push_back(std::to_string(d));
    }
    int size_node = max_size(data_str);
    int height = heap.get_height();
    int display_height = height * 3 + 1;
    int display_width = size_node * (pow(2.0, height + 1) + 1) + pow(2.0, height + 1);
    std::vector<std::string> tree(display_height, std::string(display_width, ' '));
    auto bounds = get_bounds_all(height + 1);
    for(int i = 0; i < data_str.size(); i++) {
        auto coord = get_coord(i, display_width, bounds, data_str[i].size());
        tree[coord.second].replace(coord.first, data_str[i].size(), data_str[i]);
        if(i != 0){
            tree[coord.second - 1].replace(coord.first + data_str[i].size() / 2, 1, "|");
        }
        if(i <= (data_str.size() / 2) - 1) {
            tree[coord.second + 1].replace(coord.first + data_str[i].size() / 2, 1, "+");
            int left_index = left_child_index(i);
            if(left_index >= heap.size())
                continue;
            int start_x = get_coord(left_index, display_width, bounds, data_str[left_index].size()).first;
            int end_x;
            int right_index = right_child_index(i);
            if(right_index >= heap.size())
                end_x = coord.first + 1;
            else
                end_x = get_coord(right_index, display_width, bounds, data_str[right_index].size()).first;
            int diff = end_x - start_x - 1;
            tree[coord.second + 2].replace(start_x + 1, diff, std::string(diff, '-'));
        }
    }
    return tree;
}

template <typename T>
void print_heap(BinaryHeap<T> heap) {
    auto tree = get_heap_tree_str(heap);
    for(auto const& row: tree) {
        std::cout << row << '\n';
    }
}

#endif // PRINT_HEAP_H
