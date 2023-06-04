#pragma once

#include "AVL.h"

template <typename T>
int AVL<T>::_get_height(Node *&node) const
{
    return !node ? -1 : node->height;
}

template <typename T>
int AVL<T>::_get_balance_factor(Node *&node) const
{
    return !node ? 0 : _get_height(node->right) - _get_height(node->left);
}

template <typename T>
const T &AVL<T>::find(const T &key)
{
    Node *&node = _find(key, head_);
    if (node == nullptr)
        throw std::runtime_error("Key not found.");
    return node->data;
}

template <typename T>
bool AVL<T>::contains(const T &key)
{
    Node *&node = _find(key, head_);
    return node != nullptr;
}

template <typename T>
typename AVL<T>::Node *&AVL<T>::_find(const T &key, Node *&curr) const
{
    if (curr == nullptr)
        return curr;
    else if (key == curr->data)
        return curr;
    else if (key < curr->key)
        return _find(key, curr->left);
    else
        return _find(key, curr->right);
}

template <typename T>
void AVL<T>::insert(const T &key)
{
    _find_and_insert(key, head_);
}

template <typename T>
void AVL<T>::_find_and_insert(const T &key, Node *&curr)
{
    if (curr == nullptr)
        curr = new Node(key);
    else if (key == curr->data)
        throw std::runtime_error("Key already exists");
    else
    {
        _find_and_insert(key, key < curr->data ? curr->left : curr->right);
        _ensure_balance(curr);
    }
}

template <typename T>
const T &AVL<T>::remove(const T &key)
{
    const T &removed = _find_and_remove(key, head_);
    return removed;
}

template <typename T>
const T &AVL<T>::_find_and_remove(const T &key, Node *&curr)
{
    if (curr == nullptr)
        throw std::runtime_error("Key not found");
    else if (key == curr->data)
        return _remove(curr);

    const T &removed = _find_and_remove(key, key < curr->data ? curr->left : curr->right);
    _ensure_balance(curr);
    return removed;
}

template <typename T>
const T &AVL<T>::_remove(Node *&node)
{
    if (!node)
        throw std::runtime_error("remove called on nullptr");

    // Zero child remove
    if (node->left == nullptr && node->right == nullptr)
    {
        const T &data = node->data;
        delete node;
        node = nullptr;
        return data;
    }

    // One child (left) remove
    if (node->left != nullptr && node->right == nullptr)
    {
        const T &data = node->data;
        Node *temp = node;
        node = node->left;
        delete temp;
        temp = nullptr;
        return data;
    }

    // One child (right) remove
    if (node->left == nullptr && node->right != nullptr)
    {
        const T &data = node->data;
        Node *temp = node;
        node = node->right;
        delete temp;
        temp = nullptr;
        return data;
    }

    // Two child remove
    return _iop_remove(node);
}

template <typename T>
typename AVL<T>::Node *&AVL<T>::_swap_nodes(Node *&node1, Node *&node2)
{
    Node *orig1 = node1;
    Node *orig2 = node2;

    std::swap(node1->height, node2->height);

    if (node1->left == node2)
    {
        std::swap(node1->right, node2->right);
        node1->left = orig2->left;
        orig2->left = node1;
        node1 = orig2;
        return node1->left;
    }
    else if (node1->right == node2)
    {
        std::swap(node1->left, node2->left);
        node1->right = orig2->right;
        orig2->right = node1;
        node1 = orig2;
        return node1->right;
    }
    else if (node2->left == node1)
    {
        std::swap(node2->right, node1->right);
        node2->left = orig1->left;
        orig1->left = node2;
        node2 = orig1;
        return node2->left;
    }
    else if (node2->right == node1)
    {
        std::swap(node2->left, node1->left);
        node2->right = orig1->right;
        orig1->right = node2;
        node2 = orig1;
        return node2->right;
    }
    else
    {
        std::swap(node1->left, node2->left);
        std::swap(node1->right, node2->right);
        std::swap(node1, node2);
        return node2;
    }
}

template <typename T>
void AVL<T>::_update_height(Node *&node)
{
    if (!node)
        return;

    int max = std::max(_get_height(node->left), _get_height(node->right));
    node->height = 1 + max;
}

template <typename T>
void AVL<T>::_ensure_balance(Node *&node)
{
    if (!node)
        return;

    int balance = _get_balance_factor(node);

    if (balance == -2)
    {
        int l_balance = _get_balance_factor(node->left);
        if (l_balance == -1 || l_balance == 0)
            _rotate_right(node);
        else if (l_balance == 1)
            _rotate_left_right(node);
    }
    else if (balance == 2)
    {
        int r_balance = _get_balance_factor(node->right);
        if (r_balance == 1 || r_balance == 0)
            _rotate_left(node);
        else if (r_balance == -1)
            _rotate_right_left(node);
    }

    _update_height(node);
}

// https://www.geeksforgeeks.org/introduction-to-avl-tree/

template <typename T>
void AVL<T>::_rotate_left(Node *&node)
{
    if (!node)
        throw std::runtime_error("Left Rotation called on nullptr");

    Node *x = node;
    Node *y = node->right;
    Node *z = node->right->left;

    x->right = z;
    y->left = x;
    node = y;

    _update_height(x);
    _update_height(y);
}

template <typename T>
void AVL<T>::_rotate_right(Node *&node)
{
    if (!node)
        throw std::runtime_error("Rotate Right called on nullptr");

    Node *x = node;
    Node *y = node->left;
    Node *z = y->right;

    x->left = z;
    y->right = x;
    node = y;

    _update_height(x);
    _update_height(y);
}

template <typename T>
void AVL<T>::_rotate_right_left(Node *&node)
{
    if (!node)
        throw std::runtime_error("Rotate Right Left called on nullptr");

    _rotate_right(node->right);
    _rotate_left(node);
}

template <typename T>
void AVL<T>::_rotate_left_right(Node *&node)
{
    if (!node)
        throw std::runtime_error("Rotate Left Right called on nullptr");

    _rotate_left(node->left);
    _rotate_right(node);
}

template <typename T>
const T &AVL<T>::_iop_remove(Node *&target)
{
    if (!target)
        throw std::runtime_error("IOP Remove called on nullptr");

    const T &removed = _iop_remove(target, target->left, true);

    if (target->left)
        _ensure_balance(target->left);
    _ensure_balance(target);

    return removed;
}

template <typename T>
const T &AVL<T>::_iop_remove(Node *&target, Node *&ancestor, bool isInitial)
{
    if (!ancestor)
        throw std::runtime_error("Ancestor is NULL");

    if (ancestor->right != nullptr)
    {
        const T &removed = _iop_remove(target, ancestor->right, false);
        if (!isInitial && ancestor)
            _ensure_balance(ancestor);
        return removed;
    }
    else
    {
        Node *&moved = _swap_nodes(target, ancestor);
        return _remove(moved);
    }
}

template <typename T>
void AVL<T>::print() const
{

    // Stacks maintain the next node contents to display as well as the
    // corresponding amount of indentation to show in the margin.
    std::stack<Node *> node_stack;
    std::stack<int> margin_stack;

    node_stack.push(head_);
    margin_stack.push(0);

    while (!node_stack.empty())
    {

        Node *n = node_stack.top();
        node_stack.pop();

        int margin_level = margin_stack.top();
        margin_stack.pop();

        for (int i = 0; i < margin_level; i++)
            std::cout << " ";

        if (margin_level > 0)
            std::cout << "|- ";
        else
            std::cout << ". ";

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

            // show key, data pair
            std::cout << "[" << n->data << "] ";
            // balance factor
            std::cout << "Bal: " << _get_balance_factor(n) << " ";
            // height
            std::cout << "Ht: " << _get_height(n) << std::endl;
        }
        else
        {
            // no child (nullptr)
            std::cout << "[]" << std::endl;
        }
    }
}