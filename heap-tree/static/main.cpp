#include <iostream>

#include "heap-tree.h"

int main()
{
    BinaryHeap<int> heap(10);
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.print();

    heap.extractMax();
    heap.extractMax();
    heap.extractMax();
    heap.print();
}