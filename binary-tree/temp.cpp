#include <iostream>
#include "BST.h"

int main()
{
    BST<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    tree.inOrder(tree.getRoot());

    tree.remove(7);
    tree.remove(2);
    tree.remove(4);
    tree.remove(3);
    tree.remove(5);

    tree.inOrder(tree.getRoot());
}