#include <iostream>

#include "AVL.h"

int main()
{
    AVL<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);

    tree.remove(5);

    tree.print();
}