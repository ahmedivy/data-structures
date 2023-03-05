#pragma once

template <typename T>
class Stack
{
public:
    Stack(int size);
    ~Stack();
    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    void print();

private:
    int size;
    int top;
    T *array;
};
