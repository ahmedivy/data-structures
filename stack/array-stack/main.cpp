#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> stack(10);
    cout << stack;
    stack.push(10);
    stack.push(30);
    stack.push(35);
    stack.push(43);
    cout << stack;
    stack.pop();
    cout << stack;
    stack.push(123);
    stack.push(245);
    cout << stack;

    return 0;
}
