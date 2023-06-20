#pragma once

#include <iostream>

class BST
{
private:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* root;

public:
    BST(): root(nullptr) {}

    void insert(int data);
    void remove(int data);
    bool search(int data);
    void print();

private:
    void insert(Node* &node, int data);
    void remove(Node* &node, int data);
    bool search(Node* node, int data);
    void print(Node* node);
};

void BST::insert(int data)
{
    insert(root, data);
}

void BST::insert(Node* &node, int data)
{
    if (node == nullptr)
    {
        node = new Node(data);
        return;
    }

    if (data < node->data)
    {
        insert(node->left, data);
    }
    else if (data > node->data)
    {
        insert(node->right, data);
    }
}

void BST::remove(int data)
{
    remove(root, data);
}

void BST::remove(Node* &node, int data)
{
    if (node == nullptr)
    {
        return;
    }

    if (data < node->data)
    {
        remove(node->left, data);
    }
    else if (data > node->data)
    {
        remove(node->right, data);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node* temp = node->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

bool BST::search(int data)
{
    return search(root, data);
}

bool BST::search(Node* node, int data)
{
    if (node == nullptr)
    {
        return false;
    }

    if (data < node->data)
    {
        return search(node->left, data);
    }
    else if (data > node->data)
    {
        return search(node->right, data);
    }
    else
    {
        return true;
    }
}

void BST::print()
{
    print(root);
}

void BST::print(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    print(node->left);
    std::cout << node->data << " ";
    print(node->right);
}