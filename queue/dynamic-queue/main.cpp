#include <iostream>
#include <string>

#include "LinkedQueue.h"

int main()
{
    LinkedQueue<int>* queue = new LinkedQueue<int>();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    queue->print();

    std::cout << "Dequeue: " << queue->dequeue() << std::endl;
    std::cout << "Dequeue: " << queue->dequeue() << std::endl;

    queue->print();

    return 0;
}