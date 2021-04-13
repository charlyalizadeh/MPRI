#include "heap.hpp"
#include "print_heap.hpp"
#include <string>


int main() {
    std::vector<int> data1({0, 4, 6, 8});
    std::vector<int> data2({1, 3, 5, 7});
    auto heap1 = MaxBinaryHeap<int>(data1);
    print_heap(heap1);
    auto heap2 = MaxBinaryHeap<int>(data2);
    print_heap(heap2);
    heap2.meld(heap1);
    print_heap(heap2);
    for(auto const& d: heap2.get_vector()) {
        std::cout << d << ',';
    }
    std::cout << std::endl;
    return 0;
}
