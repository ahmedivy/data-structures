#include <iostream>

#include "LinkedQueue.h"
#include "BinaryTree.h"

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

    // Level Order Insert
    Node* root = new Node(1);
    for (int i = 2; i < 9; i++)
        level_order_insert(root, i);

    // Is BST
    printf(is_bst(root) ? "Tree is BST.\n" : "Not a BST.\n");

    printTree(root);
//         1
//       2  3
//     4 5 6 7
//    8 

    // // Finding parent of a node
    // printf("Parent of 8: %d\n" , find_parent(root, 8)->data);

    // // Finding level/depth of a node
    // printf("Depth of 6: %d\n", find_level(root, 6));

    // // Finding height of tree
    // printf("Height of tree: %d\n", find_height(root));


  
    return 0;
}
