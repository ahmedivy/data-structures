#include <iostream>

#include "binarytree.h"

int main()
{
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);

    tree.print();
    std::cout << (tree.isAVL() ? "Tree is AVL" : "Not an AVL Tree" ) << std::endl;

    // lets make it not an AVL tree
    tree.insert(1);
    
    tree.print();
    std::cout << (tree.isAVL() ? "Tree is AVL" : "Not an AVL Tree" ) << std::endl;
}

