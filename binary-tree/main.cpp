#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(10);

    cout << "BFS: ";
    tree.bfs_iterative();
    cout << "DFS: ";
    tree.dfs_iterative();
    cout << "PreOrder: ";
    tree.preOrder(tree.getRoot());
    cout << "PostOrder: ";
    tree.postOrder(tree.getRoot());
    cout << "InOrder: ";
    tree.inOrder(tree.getRoot());

    return 0;
}