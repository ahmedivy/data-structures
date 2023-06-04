#include <iostream>

#include "avl.h"
#include "heap-tree.h"
#include "binary-tree.h"

int main()
{
    // Question 1 (Part 1)
    std::cout << "----BST----" << std::endl;
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);

    tree.print();
    std::cout << (tree.isAVL() ? "Tree is AVL" : "Not an AVL Tree") << std::endl;

    // lets make it not an AVL tree
    tree.insert(1);

    tree.print();
    std::cout << (tree.isAVL() ? "Tree is AVL" : "Not an AVL Tree") << std::endl;

    // Question 1 (Part 3)
    int data[] = {1, 2, 3, 4, 5};
    AVL *avl = new AVL(data, 5);
    avl->print();

    // Question 1 (Part 2)
    std::cout << "Tree contains 4: " << avl->contain(1) << std::endl;

    // Question 2

    std::cout << "----HEAP----" << std::endl;

    HeapTree<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(2);
    heap.insert(1);

    heap.print();

    std::cout << "Removing: " << std::endl;
    heap.remove();
    heap.print();
}
