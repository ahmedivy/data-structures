#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

template <typename T>
class LinkedList 
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
        LinkedList() : size(0), head(nullptr), tail(nullptr) {}
        ~LinkedList();
        void insertBack(T data);
        void insertFront(T data);
        bool isEmpty();
        std::string display();

};

// Implementation of LinkedList Methods

template <typename T>
LinkedList<T>::~LinkedList() {}

template <typename T>
void LinkedList<T>::insertFront(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        this->head = this->tail = newNode;
    }
    else
    {
        newNode->next = this->head;
        this->head = newNode;
    }
    this->size++;
}

template <typename T>
void LinkedList<T>::insertBack(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        this->head = this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return this->head == nullptr && this->tail == nullptr;
}

template <typename T>
std::string LinkedList<T>::display()
{
    if (isEmpty())
    {
        return "Currently Empty!";
    }
    std::string result = "";
    Node* current = this->head;
    while (current != nullptr) 
    {
        result += std::to_string(current->data) + " ";
        current = current->next;
    }
    return result;
}

#endif
