#include <iostream>

#include "PriorityQueue.h"

int main()
{
    PriorityQueue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(8);
    queue.push(9);
    queue.push(5);
    queue.push(4);
    queue.push(2);
    queue.push(10);
    queue.push(6);

    while (!queue.empty())
    {
        std::cout << queue.top() << std::endl;
        queue.pop();
    }

    return 0;
}
