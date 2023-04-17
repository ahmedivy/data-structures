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
                Node* prev;
                Node(T data) : data(data), next(nullptr), prev(nullptr) {}
        };

        Node* head;
        Node* tail;
        int size;

    public:
        LinkedList() : size(0), head(nullptr), tail(nullptr) {}
        ~LinkedList();
        void insertFront(T data);
        void insertBack(T data);
        void popFront();
        void popBack();
        void insertAt(int index, T data);
        void removeAt(int index);
        int length();
        bool isEmpty();
        std::string display();
};

// Implementation of LinkedList Methods

template <typename T>
LinkedList<T>::~LinkedList() 
{
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insertFront(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::insertBack(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::insertAt(int index, T data)
{
    if (index < 0 || index > size)
    {
        throw std::runtime_error("Index out of bounds!");
    }
    else if (index == 0)
    {
        insertFront(data);
    }
    else if (index == size)
    {
        insertBack(data);
    }
    else
    {
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        size++;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Index out of bounds!");
    }
    else if (index == 0)
    {
        popFront();
    }
    else if (index == size - 1)
    {
        popBack();
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
int LinkedList<T>::length()
{
    return size;
}

template <typename T>
std::string LinkedList<T>::display()
{
    if (isEmpty())
    {
        return "Currently Empty!";
    }
    std::string result = "";
    Node* current = head;
    while (current != nullptr) 
    {
        result += std::to_string(current->data) + " ";
        current = current->next;
    }
    return result;
}

template <typename T>
void LinkedList<T>::popFront()
{
    if (isEmpty())
    {
        throw std::runtime_error("List is Empty!");
    }
    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    size--;
}

template <typename T>
void LinkedList<T>::popBack()
{
    if (isEmpty())
    {
        throw std::runtime_error("List is Empty!");
    }
    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    size--;
}

#endif
