#pragma once

#include <iostream>

using namespace std;

template<class T>
class Queue
{
    private:
        int front;
        int back;
        int size;
        T *array;

    public:
        Queue(int size)
        {
            this->size = size;
            this->front = -1;
            this->back = -1;
            this->array = new T[size];
        }

        ~Queue()
        {
            delete[] array;
        }

        bool isEmpty() const
        {
            return front == -1 && back == -1;
        }

        bool isFull()
        {
            return back + 1 == size;
        }

        void push(T value)
        {
            if (isFull())
            {
                throw runtime_error("Queue is Full!");
            }
            if (isEmpty())
            {
                this->front++;
            }
            array[++this->back] == value;
        }

        T pop()
        {
            if (isEmpty())
            {
                throw runtime_error("Queue is Empty!");
            }
            if (this->front == this->back)
            {
                T value = array[this->front];
                this->front = -1;
                this->back = -1;
                return value;
            }
            return array[this->front--];
        }

        T peek()
        {
            if (isEmpty())
            {
                throw runtime_error("Queue is Empty!");
            }
            return array[this->front];
        }

        friend ostream &operator<<(ostream &os, const Queue<T> &q)
		{
			if (q.isEmpty())
				return os << "Queue: Currently Empty" << endl;
			os << "Queue: ";
			for (int i = q.front; i < q.back + 1; i++)
			{
				os << q.array[i] << " ";
			}
			os << endl;
			return os;
		}
};