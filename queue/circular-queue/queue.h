#pragma once
#include <iostream>

using namespace std;

template <class T>
class Queue
{
    private:
        T *arr;
        int size;
        int front;
        int rear;

    public:
        Queue(int size)
        {
            this->size = size;
            arr = new T[size];
            front = -1;
            rear = -1;
        }

        ~Queue()
        {
            delete[] arr;
        }

        bool isEmpty()
        {
            return front == -1 && rear == -1;
        }

        bool isFull()
        {
            return (front == 0 && rear == size - 1) || (front == rear + 1);
        }

        void enqueue(T data)
        {
            if (isFull())
            {
                cout << "Queue is full" << endl;
                return;
            }
            else if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % size;
            }
            arr[rear] = data;
        }

        T dequeue()
        {
            T data = 0;
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return data;
            }
            else if (front == rear)
            {
                data = arr[front];
                front = rear = -1;
            }
            else
            {
                data = arr[front];
                front = (front + 1) % size;
            }
            return data;
        }

        T peek()
        {
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return 0;
            }
            return arr[front];
        }

        int count()
        {
            return (size - front + rear + 1) % size;
        }

        string display()
        {
            string result = "";
            if (isEmpty())
            {
                return "Currently Empty";
            }
            else
            {
                int i = front;
                while (i != rear)
                {
                    result += to_string(arr[i]) + " ";
                    i = (i + 1) % size;
                }
                result += to_string(arr[i]);
            }
            return result;
        }
};