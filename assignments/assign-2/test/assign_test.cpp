#include <iostream>
#include <cassert>

#include "binarytree.h"
#include "linked_queue.h"
#include "bst.h"

void test_linked_queue()
{
    LinkedQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Test removeSecond
    try
    {
        int second = queue.removeSecond();
        assert(second == 2);
        std::cout << "\033[32mTest passed[Queue->Remove Second] = Expected(2) Got(" << second << ")\033[0m\n";
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[31mTest failed[Queue->Remove Second]: " << e.what() << "\033[0m\n";
    }

    // Test reverse
    queue.reverse();
    int expected[] = {3, 1};
    int i = 0;
    while (!queue.isEmpty())
    {
        try
        {
            int data = queue.dequeue();
            assert(data == expected[i++]);
        }
        catch (std::exception &e)
        {
            std::cerr << "\033[31mTest failed[Queue->Reverse]: " << e.what() << "\033[0m\n";
        }
    }
    std::cout << "\033[32mTest passed[Queue->Reverse] = Expected(3, 1) Got(3, 1)\033[0m\n";
}

// Tree Test
void test_tree_methods()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Node *parent = find_parent(root, 4);
    if (parent && parent->data == 3)
        std::cout << "\033[32mTest passed[BST->find_parent] = Expected parent node is returned for child node\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->find_parent] = Expected parent node is not returned for child node\033[0m\n";

    int level = find_level(root, 4);
    if (level == 2)
        std::cout << "\033[32mTest passed[BST->find_level] = Expected level of node is returned\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->find_level] = Expected level of node is not returned\033[0m\n";

    int height = find_height(root);
    if (height == 3)
        std::cout << "\033[32mTest passed[BST->find_height] = Expected height of tree is returned\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->find_height] = Expected height of tree is not returned\033[0m\n";
}

void test_is_same_level()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (is_same_level(root, 1, 5))
        std::cout << "\033[32mTest passed[BST->is_same_level] = Expected nodes are on the same level\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->is_same_level] = Expected nodes are not on the same level\033[0m\n";
}

void test_count_nodes()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (count_nodes(root) == 7)
        std::cout << "\033[32mTest passed[BST->count_nodes] = Expected number of nodes in tree is returned\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->count_nodes] = Expected number of nodes in tree is not returned\033[0m\n";
}

// Test a valid BST
void test_valid_bst()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    if (is_bst(root))
        std::cout << "\033[32mTest passed[BST->isBST] = Expected (Valid BST) Got(Valid BST)\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->isBST] = Expected (Valid BST) Got(Invalid BST)\033[0m\n";
}

// Test an invalid BST
void test_invalid_bst()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(2);

    if (!is_bst(root))
        std::cout << "\033[32mTest passed[BST->isBST] = Expected (Invalid BST) Got(Invalid BST)\033[0m\n";
    else
        std::cout << "\033[31mTest failed[BST->isBST] = Expected (Invalid BST) Got(Valid BST)\033[0m\n";
}

void test_level_order_insert()
{
    // Test 1: Insert root node
    BST<int> tree1;
    tree1.levelOrder(1);
    if (tree1.getRoot()->data == 1 && tree1.getRoot()->left == nullptr && tree1.getRoot()->right == nullptr)
        std::cout << "\033[32mTest Passed[BST->levelOrderInsert]: Insert root node\033[0m\n";
    else
        std::cout << "\033[31mTest Failed[BST->levelOrderInsert]: Insert root node\033[0m\n";

    // Test 2: Insert left child of root
    BST<int> tree2;
    tree2.levelOrder(1);
    tree2.levelOrder(2);
    if (tree2.getRoot()->data == 1 && tree2.getRoot()->left->data == 2 && tree2.getRoot()->right == nullptr)
        std::cout << "\033[32mTest Passed[BST->levelOrderInsert]: Insert left child of root\033[0m\n";
    else
        std::cout << "\033[31mTest Failed[BST->levelOrderInsert]: Insert left child of root\033[0m\n";

    // Test 3: Insert right child of root
    BST<int> tree3;
    tree3.levelOrder(1);
    tree3.levelOrder(2);
    tree3.levelOrder(3);
    if (tree3.getRoot()->data == 1 && tree3.getRoot()->left->data == 2 && tree3.getRoot()->right->data == 3)
        std::cout << "\033[32mTest Passed[BST->levelOrderInsert]: Insert right child of root\033[0m\n";
    else
        std::cout << "\033[31mTest Failed[BST->levelOrderInsert]: Insert right child of root\033[0m\n";

    // Test 4: Insert left and right children of root
    BST<int> tree4;
    tree4.levelOrder(1);
    tree4.levelOrder(2);
    tree4.levelOrder(3);
    tree4.levelOrder(4);
    if (tree4.getRoot()->data == 1 && tree4.getRoot()->left->data == 2 && tree4.getRoot()->right->data == 3 && tree4.getRoot()->left->left->data == 4)
        std::cout << "\033[32mTest Passed[BST->levelOrderInsert]: Insert left and right children of root\033[0m\n";
    else
        std::cout << "\033[31mTest Failed[BST->levelOrderInsert]: Insert left and right children of root\033[0m\n";
}

void run_test()
{
    test_linked_queue();
    test_tree_methods();
    test_valid_bst();
    test_invalid_bst();
    test_is_same_level();
    test_count_nodes();
    test_level_order_insert();

    std::cout << "\n\n\033[34mAll tests completed!\033[0m\n" << std::endl;
}
