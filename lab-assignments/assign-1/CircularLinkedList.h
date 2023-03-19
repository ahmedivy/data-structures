#pragma once

#include <iostream>
#include <string>

template <typename T>
class CircularLinkedList
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
        int size;

    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void insertFront(T data);
        void insertBack(T data);
        void removeFront();
        void removeBack();
        void display();
        int getSize();
        bool isEmpty();
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr), size(0) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Node* current = head;
    do
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    while (current != head);
    delete current;
}

template <typename T>
void CircularLinkedList<T>::insertFront(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
void CircularLinkedList<T>::insertBack(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
void CircularLinkedList<T>::removeFront()
{
    if (isEmpty())
    {
        return;
    }
    else if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = head->next;
        delete head;
        head = current->next;
    }
    size--;
}