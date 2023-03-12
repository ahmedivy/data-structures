#include <iostream>
#include <string>
#include "LinkedList.h"

int main() 
{
    LinkedList<int> list;
    std::cout << "Linked List: " << list.display() << std::endl;
    list.insertBack(42);
    std::cout << "Linked List: " << list.display() << std::endl;
    list.insertBack(60);
    std::cout << "Linked List: " << list.display() << std::endl;
    list.insertFront(34);
    std::cout << "Linked List: " << list.display() << std::endl;
    list.popFront();
    list.popFront();
    list.popFront();
    std::cout << "Linked List: " << list.display() << std::endl;
    list.insertBack(12);
    list.insertBack(17);
    list.insertBack(23);
    std::cout << "Linked List: " << list.display() << std::endl;
    list.popBack();
    std::cout << "Linked List: " << list.display() << std::endl;
    std::cout << "Size: " << list.length() << std::endl;
    
    return 0;
}
