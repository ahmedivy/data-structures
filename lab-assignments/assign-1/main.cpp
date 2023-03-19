#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
using Node = typename LinkedList<T>::Node;

template <typename T>
Node<T>* copyList(Node<T>* list);

int main()
{
    LinkedList<int>* list = new LinkedList<int>();
    list->insertBack(2);
    list->insertBack(4);

    LinkedList<int>* copyList = list->copy();

    LinkedList<int>* listTwo = new LinkedList<int>();
    listTwo->insertBack(6);
    listTwo->insertBack(8);

    LinkedList<int>* concatented = list->concat(listTwo);
    concatented->display();

    delete copyList;
    delete list;
    delete listTwo;

    concatented->display();
    concatented->replace(2, 5);
    concatented->display();
    std::cout << concatented->secondToLast() << std::endl;
    concatented->rotate(2);
    concatented->display();


    delete concatented;
    return 0;
}

template <typename T>
Node<T>* copyList(const Node<T>* list)
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
        Node<T>* newNode = new Node<T>(current->data);
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
