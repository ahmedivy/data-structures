#include <iostream>
#include <queue>

#include "binarytree.h"

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

int find_level(Node *root, int key, int level)
{
    if (root == nullptr && level == 0)
        return 0;
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

int min_value(Node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr)
        return root->data;
    return min_value(root->left);
}

int max_value(Node *root)
{
    if (root == nullptr)
        return 0;
    if (root->right == nullptr)
        return root->data;
    return max_value(root->right);
}

bool is_bst(Node *root)
{
    if (root == nullptr)
        return true;
    bool right = is_bst(root->right);
    bool left = is_bst(root->left);
    return (
        right && left
        && (root->left == nullptr || max_value(root->left) < root->data)
        && (root->right == nullptr || min_value(root->right) > root->data)
    );
}

bool is_same_level(Node *root, int one, int two)
{
    return find_level(root, one) == find_level(root, two);
}

int count_nodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int left = count_nodes(root->left);
    int right = count_nodes(root->right);
    return 1 + left + right;
}

void print_tree(Node* node, int level, bool is_left)
{
    if (node == nullptr)
        return;
    print_tree(node->right, level+1, false);
    std::string prefix = "";
    if (level > 0)
    {
        for (int i = 0; i < level - 1; i++)
            prefix += "    ";
        prefix += "|--- ";
    }
    std::cout << prefix << node->data << std::endl;
    print_tree(node->left, level+1, true);
}

