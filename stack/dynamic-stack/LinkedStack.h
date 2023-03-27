#pragma once

#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
class LinkedStack
{
    private:
        LinkedList<T>* list;

    public:
        LinkedStack();
        ~LinkedStack();
        void push(T data);
        T pop();
        T peek();
        int size();
        bool isEmpty();
        void display();
};

// Implementation of LinkedStack Methods

template <typename T>
LinkedStack<T>::LinkedStack()
{
    list = new LinkedList<T>();
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    delete list;
}

template <typename T>
void LinkedStack<T>::push(T data)
{
    list->insertFront(data);
}

template <typename T>
T LinkedStack<T>::pop()
{
    T data = list->getHeadPtr()->data;
    list->deleteFront();
    return data;
}

template <typename T>
T LinkedStack<T>::peek()
{
    return list->getHeadPtr()->data;
}

template <typename T>
int LinkedStack<T>::size()
{
    return list->length();
}

template <typename T>
bool LinkedStack<T>::isEmpty()
{
    return list->isEmpty();
}

template <typename T>
void LinkedStack<T>::display()
{
    list->display();
}
