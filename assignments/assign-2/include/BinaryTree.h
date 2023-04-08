#pragma once

#include <iostream>

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() = default;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
} Node;

Node *create_sample_tree()
{
    // Return a tree
    //       5
    //      / \
    //     3   8
    //    / \ / \
    //   1  4 6  12

    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(12);
    return root;
}

Node *find_parent(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->left && root->left->data == key)
        return root;
    if (root->right && root->right->data == key)
        return root;
    if (key < root->data)
        find_parent(root->left, key);
    if (key > root->data)
        find_parent(root->right, key);
    return nullptr;
}

int find_level(Node *root, int key, int level = 0)
{
    if (root == nullptr && level == 0)
        throw std::runtime_error("Empty Tree.");
    if (root->data == key && level == 0)
        return 0;
    if (root->left && root->left->data == key)
        return ++level;
    if (root->right && root->right->data == key)
        return ++level;
    if (key < root->data)
        level = find_level(root->left, key, ++level);
    else if (key > root->data)
        level = find_level(root->right, key, ++level);
    return level;
}

int find_height(Node *root)
{
    if (root == nullptr)
        return 0;
    int left_h = find_height(root->left);
    int right_h = find_height(root->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}

bool is_bst(Node* root)
{
   return true;  
}

bool is_same_level(Node* root, int one, int two)
{
    return find_level(root, one) == find_level(root, two);
}

int count_nodes(Node* root)
{
    if (root == nullptr)
        return 0;
    int left_c = count_nodes(root->left);
    int right_c = count_nodes(root->right);
    return 1 + left_c + right_c;
}

