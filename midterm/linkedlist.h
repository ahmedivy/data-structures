#pragma once

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
    int size;
public:
    LinkedList();
    void insert_back(T data);
    void remove_duplicates();
    void print();
    std::string search(int id);
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <typename T>
void LinkedList<T>::insert_back(T data)
{
    Node* node = new Node(data);
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove_duplicates()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* runner = current;
        while (runner->next != nullptr)
        {
            if (runner->next->data->equal(current->data))
            {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
                size--;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::print()
{
    std::cout << "\n---Employee Details---" << std::endl;
    Node* current = head;
    while (current != nullptr)
    {
        current->data->print();
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
std::string LinkedList<T>::search(int id)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data->id == id)
        {
            return current->data->name;
        }
        current = current->next;
    }
    return "none";
}

