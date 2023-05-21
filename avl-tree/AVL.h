#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class AVL
{
public:
    AVL() : head_(nullptr) {}
    void insert(const T &key);
    const T &find(const T &key);
    bool contains(const T &key);
    const T &remove(const T &key);

private:
    class Node
    {
    public:
        int height;
        const T &data;
        Node *left, *right;

        Node(const T &val)
            : data(val), left(nullptr), right(nullptr), height(0) {}
    };

    Node *head_;

    // Helper Functions
    Node *&_find(const T &key, Node *&curr) const;
    const T &_remove(Node *&node);
    void _find_and_insert(const T &key, Node *&curr);
    const T &_find_and_remove(const T &key, Node *&curr);
    const T &_iop_remove(Node *&target);
    const T &_iopRemove(Node *&targetNode, Node *&iopAncestor, bool isInitialCall);
    Node *&_swap_nodes(Node *&node1, Node *&node2);
    void _update_height(Node *&curr);
    void _ensure_balance(Node *&curr);
    void _rotate_left(Node *&curr);
    void _rotate_right(Node *&curr);
    void _rotate_right_left(Node *&curr);
    void _rotate_left_right(Node *&curr);

    int _get_height(Node *&node) const
    {
        return !node ? -1 : node->height;
    }

    int _get_balance_factor(Node *&node) const
    {
        return !node ? 0 : _get_height(node->right) - _get_height(node->left);
    }
};
