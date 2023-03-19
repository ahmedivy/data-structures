#include <iostream>
#include <string>
#include "LinkedList.h"

int main() 
{
    LinkedList<int> ll;

    std::cout << (ll.search(56) == -1 ? "56 not found" : "56 found") << std::endl;
    
    ll.insertFront(56);
    ll.insertBack(7);

    std::cout << (ll.search(7) == -1 ? "7 not found" : "7 found") << std::endl;
    ll.display();

    ll.insertBack(4);
    ll.insertBack(8);
    ll.insertBack(12);
    ll.insertBack(99);

    ll.display();

    ll.deleteAt(2);
    ll.display();

    ll.deleteAt(2);
    ll.display();

    ll.insertAt(2, 100);
    ll.insertBack(200);
    ll.display();

    ll.reverse();
    ll.display();

    LinkedList<int>* ll2 = ll.copy();
    ll2->display();

    ll.deleteAt(0);
    ll.display();
    ll2->display();

    return 0;
}
