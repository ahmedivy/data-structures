#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q(10);
    q.push(10);
    q.push(20);
    cout << q << endl;
    q.pop();
    cout << q << endl;

    return 0;
}
