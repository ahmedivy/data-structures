#include <iostream>

#include "avl.h"

int main()
{
    AVL avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    avl.print();

    avl.remove(30);

    avl.print();

    avl.insert(30);

    avl.print();

}