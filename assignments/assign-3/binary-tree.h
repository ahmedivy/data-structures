#pragma once

#include <stack>
#include <iostream>

template <typename T>
class BinaryTree
{
private:
    class Node
    {
    public:
        T data;
        Node *left;
        Node *right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
        ~Node()
        {
            delete left;
            delete right;
        }
    };
    Node *root;

public:
    BinaryTree();
    ~BinaryTree();
    bool isAVL();
    void insert(T data);
    bool isAVL(Node *node);
    int height(Node *node);
    void print();
};

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
}

template <typename T>
void BinaryTree<T>::insert(T data)
{
    Node *newNode = new Node(data);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    Node *parent = nullptr;

    while (true)
    {
        parent = current;

        if (data < current->data)
        {
            current = current->left;
            if (current == nullptr)
            {
                parent->left = newNode;
                return;
            }
        }
        else
        {
            current = current->right;
            if (current == nullptr)
            {
                parent->right = newNode;
                return;
            }
        }
    }
}

template <typename T>
int BinaryTree<T>::height(Node* node)
{
    if (!node)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}

template <typename T>
bool BinaryTree<T>::isAVL()
{
    return isAVL(root);
}

template <typename T>
bool BinaryTree<T>::isAVL(Node *node)
{
    if (!node)
        return true;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
        
    return isAVL(node->left) && isAVL(node->right);
}

template <typename T>
void BinaryTree<T>::print()
{
    // Stacks maintain the next node contents to display as well as the
    // corresponding amount of indentation to show in the margin.
    std::stack<Node*> node_stack;
    std::stack<int> margin_stack;

    node_stack.push(root);
    margin_stack.push(0);

    while (!node_stack.empty())
    {
        Node* n = node_stack.top();
        node_stack.pop();

        int margin_level = margin_stack.top();
        margin_stack.pop();

        for (int i = 0; i < margin_level; i++)
            std::cout << "   ";

        std::cout << "|- ";

        if (n)
        {
            // Only push child markers if at least one child exists.
            // This makes the leaf output clearer: if both children are nullptr,
            // they are simply not printed.
            if (n->left || n->right)
            {
                node_stack.push(n->right);
                margin_stack.push(margin_level + 1);
                node_stack.push(n->left);
                margin_stack.push(margin_level + 1);
            }

            // show data
            std::cout << n->data << std::endl;
        }
        else
        {
            // no child (nullptr)
            std::cout << "NULL" << std::endl;
        }
    }
}