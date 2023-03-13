#include <iostream>
#include <string>
#include <cassert>
#include "LinkedList.h"

void runTests();

int main()
{
    try
    {
        runTests();
        std::cout << "All tests passed!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void runTests()
{
    LinkedList<int> ll;
    assert(ll.isEmpty());
    ll.insertFront(56);
    assert(!ll.isEmpty());
    assert(ll.length() == 1);
    assert(ll.search(56) == 0);
    assert(ll.search(7) == -1);
    ll.insertBack(7);
    assert(ll.length() == 2);
    assert(ll.search(7) == 1);
    ll.insertAt(1, 4);
    assert(ll.length() == 3);
    assert(ll.search(4) == 1);
    ll.deleteAt(1);
    assert(ll.length() == 3);
    assert(ll.search(4) == -1);
}