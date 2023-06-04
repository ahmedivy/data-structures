#pragma once

#include <stack>
#include <cmath>
#include <iostream>

class AVL
{
private:
    class Node
    {
    public:
        int key;
        int height;
        Node *left;
        Node *right;

        Node(int key)
        {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 0;
        }

        Node(int key, Node *left, Node *right)
        {
            this->key = key;
            this->left = left;
            this->right = right;
            this->height = 1 + std::max(nodeHeight(left), nodeHeight(right));
        }

        int nodeHeight(Node *node)
        {
            return node == nullptr ? -1 : node->height;
        }
    };

    Node *root;

public:
    AVL();
    AVL(int *arr, int size);
    void insert(int data);
    int height(Node *node);
    Node *grow(Node *node, int key);
    void reBalance(Node *node);
    void rotateLeft(Node *node);
    void rotateRight(Node *node);
    void print();
    bool contain(int data);
};

AVL::AVL()
{
    this->root = nullptr;
}

AVL::AVL(int *arr, int size)
{
    this->root = nullptr;
    for (int i = 0; i < size; i++)
        this->insert(arr[i]);
}

void AVL::insert(int data)
{
    this->root = grow(root, data);
}

typename AVL::Node *AVL::grow(AVL::Node *node, int key)
{
    if (node == nullptr)
        return new Node(key);

    if (key == node->key)
        return node;

    if (key < node->key)
        node->left = grow(node->left, key);
    else if (key > node->key)
        node->right = grow(node->right, key);

    reBalance(node);
    node->height = 1 + std::max(height(node->left), height(node->right));
    return node;
}

void AVL::reBalance(Node *node)
{
    if (height(node->right) > height(node->left) + 1)
    {
        if (height(node->right->left) > height(node->right->right))
            rotateRight(node->right);
        rotateLeft(node);
    }
    else if (height(node->left) > height(node->right) + 1)
    {
        if (height(node->left->right) > height(node->left->left))
            rotateLeft(node->left);
        rotateRight(node);
    }
}

void AVL::rotateLeft(Node *node)
{
    node->left = new Node(node->key, node->left, node->right->left);
    node->key = node->right->key;
    Node *temp = node->right;
    node->right = node->right->right;
    delete temp;
}

void AVL::rotateRight(Node *node)
{
    node->right = new Node(node->key, node->left->right, node->right);
    node->key = node->left->key;
    Node *temp = node->left;
    node->left = node->left->left;
    delete temp;
}

int AVL::height(Node *node)
{
    return node == nullptr ? -1 : node->height;
}

bool AVL::contain(int value)
{
    Node *node = root;
    while (node != nullptr)
    {
        if (node->key == value)
            break;
        else if (value > node->key)
            node = node->right;
        else if (value < node->key)
            node = node->left;
    }
    return node;
}

void AVL::print()
{
    // Stacks maintain the next node contents to display as well as the
    // corresponding amount of indentation to show in the margin.
    std::stack<Node *> node_stack;
    std::stack<int> margin_stack;

    node_stack.push(root);
    margin_stack.push(0);

    while (!node_stack.empty())
    {

        Node *n = node_stack.top();
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
            std::cout << n->key << std::endl;
        }
        else
        {
            // no child (nullptr)
            std::cout << "NULL" << std::endl;
        }
    }
}
