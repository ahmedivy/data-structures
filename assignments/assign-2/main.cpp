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

    Node* root = create_sample_tree();

    // Finding parent of a node
    printf("Parent of 8: %d\n" , find_parent(root, 8)->data);

    // Finding level/depth of a node
    printf("Depth of 6: %d\n", find_level(root, 6));

    // Finding height of tree
    printf("Height of tree: %d\n", find_height(root));

    // Counting Nodes
    printf("Total Nodes: %d\n", count_nodes(root));

    // Is BST
    printf(is_bst(root) ? "Tree is BST." : "Not a BST");

    // Level Order Insert
    Node* root2 = new Node(8);
    level_order_insert(root2, 2);
    level_order_insert(root2, 3);
    level_order_insert(root2, 4);
    level_order_insert(root2, 6);
    level_order_insert(root2, 9);

    
    return 0;
}