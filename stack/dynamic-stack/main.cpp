#include <iostream>
#include <string>

#include "LinkedStack.h"

int main()
{
    LinkedStack<int>* stack = new LinkedStack<int>();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->display();
    std::cout << "Popped: " << stack->pop() << std::endl;
    std::cout << "Popped: " << stack->pop() << std::endl;
    std::cout << "Popped: " << stack->pop() << std::endl;
    stack->display();

    return 0;
}
