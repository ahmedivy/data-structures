#pragma once

#include <iostream>
#include <string>

template <typename T>
class LinkedQueue
{
    private:
        class Node
        {
            public:
                T data;
                Node* next;
                Node(T data) : data(data), next(nullptr) {}
        };

        Node* head;
        Node* tail;
        int size;

    public:
        LinkedQueue();
        ~LinkedQueue();
        bool isEmpty();
        int getSize();
        void enqueue(T data);
        T dequeue();
        T peek();
        void print();
};

template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
bool LinkedQueue<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
int LinkedQueue<T>::getSize()
{
    return size;
}

template <typename T>
void LinkedQueue<T>::enqueue(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
T LinkedQueue<T>::dequeue()
{
    if (isEmpty())
    {
        throw std::string("Queue is empty");
    }
    Node* temp = head;
    T data = temp->data;
    head = head->next;
    delete temp;
    size--;
    return data;
}

template <typename T>
T LinkedQueue<T>::peek()
{
    if (isEmpty())
    {
        throw std::string("Queue is empty");
    }
    return head->data;
}

template <typename T>
void LinkedQueue<T>::print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
