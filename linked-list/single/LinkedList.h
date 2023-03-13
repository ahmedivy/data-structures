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
        void insertAt(int index, T data);
        void deleteAt(int index);
        int search(T data);
        void insertFront(T data);
        void insertBack(T data);
        void deleteFront();
        void deleteBack();
        int length();
        bool isEmpty();
        std::string display();
        Node& getHeadPtr()
        {
            return head;
        }
        Node& getTailPtr()
        {
            return tail;
        }

};

// Implementation of LinkedList Methods

template <typename T>
void LinkedList<T>::insertAt(int index, T data)
{
    if (index < 0 || index > size)
    {
        throw std::runtime_error("Index out of bounds!");
    }

    // Special case: insert at the front
    if (index == 0)
    {
        insertFront(data);
        return;
    }

    // Special case: insert at the end
    if (index == size)
    {
        insertBack(data);
        return;
    }

    Node* newNode = new Node(data);
    Node* current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index - 1)
        {
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
        count++;
    }
    size++;
}

template <typename T>
void LinkedList<T>::deleteAt(int index)
{
    if (index < 0 || index > size)
    {
        throw std::runtime_error("Index out of range.");
    }

    if (index == 0)
    {
        deleteFront();
        return;
    }

    if (index == size - 1)
    {
        deleteBack();
        return;
    }
    Node* current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index - 1)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            break;
        }
        current = current->next;
        count++;
    }
}

template <typename T>
int LinkedList<T>::search(T data)
{
    Node* current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return count;
        }
        current = current->next;
        count++;
    }
    return -1;
}


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
void LinkedList<T>::deleteFront()
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
void LinkedList<T>::deleteBack()
{
    if (isEmpty())
    {
        throw std::runtime_error("List is Empty!");
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    Node *temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    size--;
}

#endif
