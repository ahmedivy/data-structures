#include <iostream>
#include <string>
#include "LinkedList.h"

int main() 
{
    LinkedList<int> list;
    std::cout << "Linked List: " << list.display() << std::endl;
    list.insert(42);
    std::cout << "Linked List: " << list.display() << std::endl;
    return 0;
}
