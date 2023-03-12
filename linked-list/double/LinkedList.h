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
    if (head == nullptr)
    {
        throw std::runtime_error("List is Empty!");
    }
    Node *temp = head; // This is the node that is being deleted
    head = head->next; // This is the new head
    delete temp;
    // If list becomes empty after deleting node
    if (isEmpty())
    {
        tail = nullptr;
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
        delete temp;
        tail->next = nullptr;
    }
    size--;
}

#endif
