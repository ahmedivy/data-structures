#pragma once

#include <iostream>
#include <string>

template <typename T>
class PriorityQueue
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *prev;

        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    Node *head;
    Node *tail;
    int size;

public:
    PriorityQueue();
    ~PriorityQueue();
    void push(T data);
    void pop();
    T &top();
    bool empty();
    int get_size();
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    while (!this->empty())
    {
        this->pop();
    }
}

template <typename T>
void PriorityQueue<T>::push(T data)
{
    Node *newNode = new Node(data);

    if (this->empty())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        Node *current = this->head;

        while (current != nullptr && current->data < data)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        else if (current == this->head)
        {
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
        else
        {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    this->size++;
}

template <typename T>
void PriorityQueue<T>::pop()
{
    if (this->empty())
    {
        throw std::out_of_range("Priority queue is empty!");
    }

    Node *toDelete = this->head;

    if (this->head == this->tail)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        this->head = this->head->next;
        this->head->prev = nullptr;
    }

    delete toDelete;
    this->size--;
}

template <typename T>
T &PriorityQueue<T>::top()
{
    if (this->empty())
    {
        throw std::out_of_range("Priority queue is empty!");
    }

    return this->head->data;
}

template <typename T>
bool PriorityQueue<T>::empty()
{
    return this->size == 0;
}

template <typename T>
int PriorityQueue<T>::get_size()
{
    return this->size;
}

