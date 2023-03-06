#pragma once

#include <iostream>

using namespace std;

template <class T>
class Stack
{
	private:
		int size;
		int top;
		T *array;

	public:
		Stack(int size)
		{
			this->size = size;
			this->top = -1;
			this->array = new int[size];
		}

		~Stack()
		{
			delete[] array;
		}

		void push(T value)
		{
			if (isFull())
			{
				throw runtime_error("Stack Overflows! 😤");
			}
			array[++top] = value;
		}

		T pop()
		{
			if (isEmpty())
			{
				throw runtime_error("Stack is Empty! 😴");
			}
			return array[top--];
		}

		T peek()
		{
			if (isEmpty())
			{
				throw runtime_error("Stack is Empty! 😴");
			}
			return array[top];
		}

		bool isEmpty() const
		{
			return top == -1;
		}

		bool isFull()
		{
			return top + 1 == size;
		}

		string display()
		{
			if (isEmpty())
			{
				return "Currently Empty";
			}
			string result = "";
			for (int i = 0; i < top + 1; i++)
			{
				result += to_string(array[i]) + " ";
			}
			return result;
		}

		friend ostream &operator<<(ostream &os, const Stack<T> &s)
		{
			if (s.isEmpty())
				return os << "Stack: Currently Empty" << endl;
			os << "Stack: ";
			for (int i = 0; i < s.top + 1; i++)
			{
				os << s.array[i] << " ";
			}
			os << endl;
			return os;
		}
};
