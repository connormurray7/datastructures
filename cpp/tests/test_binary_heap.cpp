#include "catch.hpp"
#include "../data_structures/tree/binary_heap/BinaryHeap.cpp"
#include <string>

using std::string;

TEST_CASE("Test push and pop", "[Binary Heap]" ) {
    BinaryHeap<int, string> heap;
    heap.push(0, "0");
    heap.push(1, "1");
    heap.push(2, "2");
    heap.push(3, "3");
    heap.push(4, "4");

    REQUIRE(heap.top() == "0");
    heap.pop();
    //REQUIRE(heap.pop() == "0");
    //REQUIRE(heap.pop() == "0");
    //REQUIRE(heap.pop() == "0");
    //REQUIRE(heap.pop() == "0");
}

