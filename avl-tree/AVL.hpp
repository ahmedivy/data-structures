#pragma once

#include "AVL.h"

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
    _find_and_insert(key, _head);
}

template <typename T>
void AVL<T>::_find_and_insert(const T &key, Node *&curr)
{
    if (curr == nullptr)
        curr = new Node(key);
    else if (key == curr->key)
        throw std::runtime_error("Key already exists");
    else
    {
        _find_and_insert(key, key < curr->key ? curr->left : curr->right);
        _ensure_balance(curr);
    }
}

template <typename T>
const T &AVL<T>::remove(const T &key)
{
    const T &removed = _find_and_remove(key, _head);
    return removed;
}

template <typename T>
const T &AVL<T>::_find_and_remove(const T &key, Node *&curr)
{
    if (curr == nullptr)
        throw std::runtime_error("Key not found");
    else if (key == curr->key)
        return _remove(curr);

    const T &removed = _find_and_remove(key, key < curr->key ? curr->left : curr->right);
    _ensure_balance(curr);
    return removed;
}