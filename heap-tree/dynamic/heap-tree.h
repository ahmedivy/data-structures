#pragma once

#include <stack>
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class HeapTree
{
private:
    class Node
    {
    public:
        T data;
        Node *left, *right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
        ~Node()
        {
            delete left;
            delete right;
        }
    };

    Node *root;
    Node *last;

    void heapifyUp(Node *node);
    void heapifyDown(Node *node);

public:
    HeapTree();
    ~HeapTree();
    void insert(T data);
    T remove();
    Node *sibling(Node *node);
    Node *parent(Node* root, Node *node);
    void print();
    bool isEmpty();
};

template <typename T>
HeapTree<T>::HeapTree()
{
    this->root = nullptr;
    this->last = nullptr;
}

template <typename T>
HeapTree<T>::~HeapTree()
{
    delete root;
}

template <typename T>
typename HeapTree<T>::Node *HeapTree<T>::parent(Node* root, Node *node)
{
    if (root == nullptr || root == node)
        return nullptr;

    if (root->left == node || root->right == node)
        return root;

    Node *left = parent(root->left, node);
    Node *right = parent(root->right, node);

    if (left != nullptr)
        return left;
    
    if (right != nullptr)
        return right;

    return nullptr;
}

template <typename T>
typename HeapTree<T>::Node *HeapTree<T>::sibling(Node *node)
{
    Node *parent = this->parent(root, node);

    if (parent == nullptr)
        return nullptr;

    return parent->left == node ? parent->right : parent->left;
}

template <typename T>
void HeapTree<T>::heapifyUp(Node *node)
{
    if (node == root)
        return;

    Node *parent = this->parent(root, node);
    if (parent->data < node->data)
    {
        std::swap(parent->data, node->data);
        heapifyUp(parent);
    }
}

template <typename T>
void HeapTree<T>::heapifyDown(Node *node)
{
    if (node->left == nullptr && node->right == nullptr)
        return;

    Node *largest = node;
    if (node->left != nullptr && node->left->data > largest->data)
        largest = node->left;
    if (node->right != nullptr && node->right->data > largest->data)
        largest = node->right;

    if (largest != node)
    {
        std::swap(node->data, largest->data);
        heapifyDown(largest);
    }
}

template <typename T>
void HeapTree<T>::insert(T data)
{
    Node *newNode = new Node(data);
    Node *parent = this->parent(root, last);

    if (isEmpty())
    {
        root = last = newNode;
        return;
    }
    else if (root == last)
        root->left = newNode;
    else if (parent->left == last)
        parent->right = newNode;
    else
    {
        Node *curr = parent;
        parent = this->parent(root, parent);
        while (curr != root && parent->left != curr)
        {
            curr = parent;
            parent = this->parent(root, curr);
        }
        if (curr == root)
        {
            while (curr->left != nullptr)
                curr = curr->left;
            curr->left = newNode;
        }
        else
        {
            curr = parent->right;
            while (curr->left != nullptr)
                curr = curr->left;
            curr->left = newNode;
        }
    }
    heapifyUp(newNode);
    last = newNode;
}

template <typename T>
T HeapTree<T>::remove()
{
    if (isEmpty())
        throw std::runtime_error("Heap is Empty!");

    T data = last->data;
    if (root == last)
    {
        delete root;
        root = last = nullptr;
        return data;
    }

    std::swap(root->data, last->data);
    Node *parent = this->parent(root, last);
    Node *curr = last;

    if (parent->right == last)
    {
        delete parent->right;
        parent->right = nullptr;
        last = parent->left;
    }
    else if (parent->left == last)
    {
        delete parent->left;
        parent->left = nullptr;
        while (parent != root && parent->right != curr)
        {
            curr = parent;
            parent = this->parent(root, parent);
        }

        // If root node --> last = most right node of root
        if (parent == root)
        {
            while (parent->right != nullptr)
                parent = parent->right;
            last = parent->right;
        }
        // If not root node --> last = most right node of sibling
        else if (parent->right == curr)
        {
            Node *node = this->sibling(curr);
            while (node->right != nullptr)
                parent = node->right;
            last = node->right;
        }
    }
    heapifyDown(root);
    return data;
}

template <class T>
bool HeapTree<T>::isEmpty()
{
    return root == nullptr;
}

template <typename T>
void HeapTree<T>::print()
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
            std::cout << n->data << std::endl;
        }
        else
        {
            // no child (nullptr)
            std::cout << "NULL" << std::endl;
        }
    }
}