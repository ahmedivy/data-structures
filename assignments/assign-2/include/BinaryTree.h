#pragma once

#include <iostream>
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() = default;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *find_parent(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    Node *node = nullptr;
    if (root->left && root->left->data == key)
        return root;
    if (root->right && root->right->data == key)
        return root;
    if (key < root->data)
        node = find_parent(root->left, key);
    else if (key > root->data)
        node = find_parent(root->right, key);
    return node;
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

bool is_bst(Node *root)
{
    if (root == nullptr || !root->left || !root->right)
        return true;
    bool right = is_bst(root->right);
    bool left = is_bst(root->left);
    return root->left->data < root->right->data && right && left;
}

bool is_same_level(Node *root, int one, int two)
{
    return find_level(root, one) == find_level(root, two);
}

int count_nodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int left_c = count_nodes(root->left);
    int right_c = count_nodes(root->right);
    return 1 + left_c + right_c;
}

void level_order_insert(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return;
    }
    if (root != nullptr)
    {
        std::queue<Node *> q;
        Node *temp = root;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->left == nullptr)
            {
                temp->left = new Node(data);
                return;
            }
            if (temp->right == nullptr)
            {
                temp->right = new Node(data);
                return;
            }
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
    }
}

void printTree(Node *node, int level = 0) 
{
    if (node != NULL) 
    {
        printTree(node->left, level + 1);
        for (int i = 0; i < 4 * level; i++)
            std::cout << " ";
        std::cout << "-> " << node->data << std::endl;
        printTree(node->right, level + 1);
    }
}
