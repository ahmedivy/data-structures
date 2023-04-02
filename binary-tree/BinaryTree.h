#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>

template <typename T>
class BinaryTree 
{
    private:
        class Node
        {
            public:
                T data;
                Node* left;
                Node* right;
                Node(T data) : data(data), left(nullptr), right(nullptr) {}
                ~Node()
                {
                    delete left;
                    delete right;
                }
        };
        Node* root;
        Node* _find(Node* node);
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(T data);
        void remove(T data);
        Node* left(Node* node);
        Node* right(Node* node);
        Node* getRoot();
        void bfs_iterative();
        void dfs_iterative();
        void preOrder(Node* node);
        void postOrder(Node* node);
        void inOrder(Node* node);
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
    Node* newNode = new Node(data);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node* temp = root;
    while (temp != nullptr)
    {
        if (data < temp->data)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
    delete newNode;
}

template <typename T>
void BinaryTree<T>::remove(T data)
{
    
}

template <typename T>
Node* BinaryTree<T>::_find(Node* node)
{

}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::left(Node* node)
{
    return node->left;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::right(Node* node)
{
    return node->right;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::getRoot()
{
    return root;
}

template <typename T>
void BinaryTree<T>::bfs_iterative()
{
    if (root != nullptr)
    {
        std::queue<Node*> q;
        Node* temp = root;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            std::cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
        std::cout << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::dfs_iterative()
{
    if (root != nullptr)
    {
        std::stack<Node*> s;
        Node* temp = root;
        s.push(temp);
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            std::cout << temp->data << " ";
            if (temp->right != nullptr)
            {
                s.push(temp->right);
            }
            if (temp->left != nullptr)
            {
                s.push(temp->left);
            }
        }
        std::cout << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::preOrder(Node* node)
{
    if (node != nullptr)
    {
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    if (node == root)
    {
        std::cout << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::postOrder(Node* node)
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
    if (node == root)
    {
        std::cout << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::inOrder(Node* node)
{
    if (node != nullptr)
    {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
    if (node == root)
    {
        std::cout << std::endl;
    }
}
