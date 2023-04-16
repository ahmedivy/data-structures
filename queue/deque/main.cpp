#include <iostream>

#include "Deque.h"

int main()
{
    Deque<int> queue;
    queue.push_front(1);
    queue.push_front(2);
    queue.push_front(3);
    queue.push_back(8);
    queue.push_back(9);

    while (!queue.empty())
    {
        std::cout << queue.front() << std::endl;
        queue.pop_front();
    }
}
