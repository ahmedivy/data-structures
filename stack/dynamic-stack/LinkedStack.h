#pragma once

#include <iostream>
#include <string>

template <typename T>
class LinkedStack
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr) {}
    };
    Node *top;
    int count;

public:
    LinkedStack();
    ~LinkedStack();
    T pop();
    T peek();
    void push(T data);
    int size();
    bool isEmpty();
    void display();
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
    top = nullptr;
    count = 0;
}

template <typename T>
void LinkedStack<T>::push(T data)
{
    Node *temp = new Node(data);
    temp->next = top;
    top = temp;
    count++;
}

template <typename T>
T LinkedStack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    else
    {
        Node *temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        count--;
        return data;
    }
}

template <typename T>
T LinkedStack<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    else
    {
        return top->data;
    }
}

template <typename T>
int LinkedStack<T>::size()
{
    return count;
}

template <typename T>
bool LinkedStack<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
void LinkedStack<T>::display()
{
    Node *temp = top;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    Node *temp = top;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
}
