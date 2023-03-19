#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
using Node = typename LinkedList<T>::Node;

template <typename T>
Node<T>* copy(Node* list);

int main()
{
    LinkedList<int> list;
    

    return 0;
}

template <typename T>
Node<T>* copy(const Node<T>* list)
{
    if (list == nullptr)
    {
        return nullptr;
    }

    Node<T>* current = list;
    Node<T>* newHead = nullptr;
    Node<T>* newTail = nullptr;

    while (current != nullptr)
    {
        Node<T>* newNode = new Node(current->data);
        newNode->next = newTail;
        newTail = newNode;
        current = current->next;

        if (newHead == nullptr)
        {
            newHead = newNode;
        }
    }

    return newHead;
}
