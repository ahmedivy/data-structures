#include <iostream>

#include "LinkedQueue.h"

int main()
{
    LinkedQueue<int> queue;
    for (int i = 1; i <= 5; i++)
        queue.enqueue(i);
    
    queue.print(); // 1 2 3 4 5
    queue.reverse(); // Reverse the queue
    queue.print(); // 5 4 3 2 1

    printf("Removed: %d\n", queue.removeSecond());
    queue.print(); // 5 3 2 1

    return 0;
}