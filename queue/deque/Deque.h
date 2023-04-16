#pragma once

#include <iostream>
#include <string>

template <typename T>
class Deque
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
    Deque();
    ~Deque();
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    T &front();
    T &back();
    bool empty();
    int get_size();
};

template <typename T>
Deque<T>::Deque()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename T>
Deque<T>::~Deque()
{
    while (!this->empty())
    {
        this->pop_front();
    }
}

template <typename T>
void Deque<T>::push_front(T data)
{
    Node *newNode = new Node(data);

    if (this->empty())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    this->size++;
}

template <typename T>
void Deque<T>::push_back(T data)
{
    Node *newNode = new Node(data);

    if (this->empty())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (this->empty())
    {
        throw std::out_of_range("Deque is empty");
    }

    Node *temp = this->head;

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

    delete temp;
    this->size--;
}

template <typename T>
void Deque<T>::pop_back()
{
    if (this->empty())
    {
        throw std::out_of_range("Deque is empty");
    }

    Node *temp = this->tail;

    if (this->head == this->tail)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
    }

    delete temp;
    this->size--;
}

template <typename T>
T &Deque<T>::front()
{
    if (this->empty())
    {
        throw std::out_of_range("Deque is empty");
    }

    return this->head->data;
}

template <typename T>
T &Deque<T>::back()
{
    if (this->empty())
    {
        throw std::out_of_range("Deque is empty");
    }

    return this->tail->data;
}

template <typename T>
bool Deque<T>::empty()
{
    return this->size == 0;
}

template <typename T>
int Deque<T>::get_size()
{
    return this->size;
}

