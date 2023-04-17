#pragma once

#include <iostream>
#include <string>

template <typename T>
class CircularQueue
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };
    Node *tail;
    int size;

public:
    CircularQueue();
    ~CircularQueue();
    void enqueue(T data);
    T dequeue();
    T &peek();
    bool empty();
    int get_size();
    void display();
};

template <typename T>
CircularQueue<T>::CircularQueue()
{
    this->tail = nullptr;
    this->size = 0;
}

template <typename T>
CircularQueue<T>::~CircularQueue()
{
    Node *temp = this->tail->next;
    while (temp != this->tail)
    {
        Node *t = temp;
        temp = temp->next;
        delete t;
    }
    delete this->tail;
}

template <typename T>
void CircularQueue<T>::enqueue(T data)
{
    Node *node = new Node(data);
    if (this->tail == nullptr)
    {
        this->tail = node;
        this->tail->next = this->tail;
    }
    else
    {
        node->next = this->tail->next;
        this->tail->next = node;
        this->tail = node;
    }
    this->size++;
}

template <typename T>
T CircularQueue<T>::dequeue()
{
    if (this->tail == nullptr)
    {
        throw std::runtime_error("Queue is empty");
    }
    Node *temp = this->tail->next;
    T data = temp->data;
    if (this->tail == this->tail->next)
    {
        this->tail = nullptr;
    }
    else
    {
        this->tail->next = temp->next;
    }
    delete temp;
    this->size--;
    return data;
}

template <typename T>
T &CircularQueue<T>::peek()
{
    if (this->tail == nullptr)
    {
        throw std::runtime_error("Queue is empty");
    }
    return this->tail->next->data;
}

template <typename T>
bool CircularQueue<T>::empty()
{
    return this->tail == nullptr;
}

template <typename T>
int CircularQueue<T>::get_size()
{
    return this->size;
}

template <typename T>
void CircularQueue<T>::display()
{
    if (this->tail == nullptr)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node *temp = this->tail->next;
    while (temp != this->tail)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}
