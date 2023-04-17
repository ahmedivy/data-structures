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

        Node* last;
        int size;

    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void insertAt(int index, T data);
        void removeAt(int index);
        void insertFront(T data);
        void insertBack(T data);
        void removeFront();
        void removeBack();
        void display();
        int getSize();
        bool isEmpty();
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : last(nullptr), size(0) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (!isEmpty())
    {
        removeFront();
    }
}

template <typename T>
void CircularLinkedList<T>::insertAt(int index, T data)
{
    if (index < 0 || index > size)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (index == 0)
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
        Node* temp = last->next;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

template <typename T>
void CircularLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (index == 0)
    {
        removeFront();
    }
    else if (index == size - 1)
    {
        removeBack();
    }
    else
    {
        Node* temp = last->next;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }
}

template <typename T>
void CircularLinkedList<T>::insertFront(T data)
{
    Node* newNode = new Node(data);
    if (isEmpty())
    {
        last = newNode;
        last->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
    size++;
}

template <typename T>
void CircularLinkedList<T>::insertBack(T data)
{
    insertFront(data);
    last = last->next;
}

template <typename T>
void CircularLinkedList<T>::removeFront()
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = last->next;
    if (last->next == last)
    {
        last = nullptr;
    }
    else
    {
        last->next = temp->next;
    }
    delete temp;
    size--;
}

template <typename T>
void CircularLinkedList<T>::removeBack()
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = last->next;
    if (last->next == last)
    {
        last = nullptr;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = last->next;
        last = temp;
    }
    delete temp;
    size--;
}

template <typename T>
void CircularLinkedList<T>::display()
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = last->next;
    while (temp != last)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}

template <typename T>
int CircularLinkedList<T>::getSize()
{
    int count = 0;
    if (isEmpty())
    {
        return count;
    }
    Node* current = last->next;
    while (current != last)
    {
        current = current->next;
        count++;
    }
    return ++count;
}

template <typename T>
bool CircularLinkedList<T>::isEmpty()
{
    return last == nullptr;
}
