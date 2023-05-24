#include <iostream>

#include "heap-tree.h"

int main()
{
    HeapTree<int> heap;
    heap.insert(20);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    heap.insert(35);

    std::cout << "After inserting some elements: " << std::endl;
    heap.print();

    heap.remove();

    std::cout << "After removing the root: " << std::endl;
    heap.print();

    heap.remove();
    std::cout << "After removing the root: " << std::endl;
    heap.print();
}