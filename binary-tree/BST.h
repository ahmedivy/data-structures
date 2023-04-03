#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>

template <typename T>
class BST 
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
    public:
        BST();
        ~BST();
        Node* insert(T data);
        Node* remove(T data);
        Node* _remove(Node* node, T data);
        Node* left(Node* node);
        Node* right(Node* node);
        Node* getRoot();
        void bfs_iterative();
        void dfs_iterative();
        void preOrder(Node* node);
        void postOrder(Node* node);
        void inOrder(Node* node);
        bool hasLeft(Node* node);
        bool hasRight(Node* node);
        Node* findSuccessor(Node* node);
        Node* find(T data);
        Node* _findParent(const T& data, Node* root);
        Node* findParent(const T& data);
        Node* findSibling(const T& data);
};


template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST()
{
    delete root;
}

template <typename T>
typename BST<T>::Node* BST<T>::insert(T data)
{
    Node* newNode = new Node(data);
    if (root == nullptr)
    {
        root = newNode;
        return newNode;
    }
    Node* temp = root;
    while (temp != nullptr)
    {
        if (data < temp->data)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return newNode;
            }
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return newNode;
            }
            temp = temp->right;
        }
        else
        {
            delete newNode;
            return nullptr;
        }
    }
    return newNode;
}

template <typename T>
typename BST<T>::Node* BST<T>::remove(T data)
{
    return _remove(root, data);
}

template <typename T>
typename BST<T>::Node* BST<T>::_remove(Node* node, T key)
{
    if (node != nullptr)
    {
        if (key == node->data)
        {
            if (hasLeft(node) && hasRight(node))
            {
                // Case 3 (Two Childs)
                Node* successor = findSuccessor(node);
                node->data = successor->data;
                node->right = _remove(node->right, successor->data);
            }
            else if (hasLeft(node) || hasRight(node))
            {
                // Case 2 (One Child)
                return hasLeft(node) ? node->left : node->right;
            }
            else 
            {
                // Case 1 (No Child)
                return nullptr;
            }
        }
        else if (key < node->data)
        {
            node->left = _remove(node->left, key);
        }
        else
        {
            node->right = _remove(node->right, key);
        }
        return node;
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::left(Node* node)
{
    return node->left;
}

template <typename T>
typename BST<T>::Node* BST<T>::right(Node* node)
{
    return node->right;
}

template <typename T>
typename BST<T>::Node* BST<T>::getRoot()
{
    return root;
}

template <typename T>
typename BST<T>::Node* BST<T>::findSuccessor(Node* node)
{
    Node* temp = node->right;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

template <typename T>
void BST<T>::bfs_iterative()
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
void BST<T>::dfs_iterative()
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
void BST<T>::preOrder(Node* node)
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
void BST<T>::postOrder(Node* node)
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
void BST<T>::inOrder(Node* node)
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

template <typename T>
typename BST<T>::Node* BST<T>::find(T data)
{
    Node* temp = root;
    while (temp != nullptr)
    {
        if (data < temp->data)
        {
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            return temp;
        }
    }
    return nullptr;
}

template <typename T>
bool BST<T>::hasLeft(Node* node)
{
    return node->left != nullptr;
}

template <typename T>
bool BST<T>::hasRight(Node* node)
{
    return node->right != nullptr;
}

template <typename T>
typename BST<T>::Node* BST<T>::_findParent(const T& data, Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (hasLeft(root) && root->left->data == data)
    {
        return root;    
    }
    if (hasRight(root) && root->right->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return _findParent(data, root->left);
    }
    else if (data > root->data)
    {
        return _findParent(data, root->right);
    }
    return nullptr;
}

template <typename T>
typename BST<T>::Node* BST<T>::findParent(const T& data)
{
    return _findParent(data, root);
}

template <typename T>
typename BST<T>::Node* BST<T>::findSibling(const T& data)
{
    Node* parent = findParent(data);
    if (parent == nullptr)
    {
        return nullptr;
    }
    if (hasLeft(parent) && parent->left->data == data)
    {
        return parent->right;
    }
    if (hasRight(parent) && parent->right->data == data)
    {
        return parent->left;
    }
    return nullptr;
}
