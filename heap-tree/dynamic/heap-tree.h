#pragma once

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
    };

    Node *root;
    Node *last;

    void heapifyUp(Node *node);
    void heapifyDown(Node *node);

public:
    HeapTree();
    // ~HeapTree();
    Node *insert(T data);
    T remove();
    Node *sibling(Node *node);
};

template <typename T>
HeapTree<T>::HeapTree()
{
    this->root = nullptr;
    this->last = nullptr;
}

