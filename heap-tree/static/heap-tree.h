#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class BinaryHeap
{
private:
    T *heap;
    int size;
    int capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    BinaryHeap(int capacity);
    ~BinaryHeap();
    T extractMax();
    T getMax();
    void insert(T value);
    int getSize();
    bool isEmpty();
    bool isFull();
    void print();
};

template <typename T>
BinaryHeap<T>::BinaryHeap(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->heap = new T[capacity];
}

template <typename T>
BinaryHeap<T>::~BinaryHeap()
{
    delete[] this->heap;
}

template <typename T>
void BinaryHeap<T>::heapifyUp(int index)
{
    if (index == 0)
        return;

    int parentIndex = (index - 1) / 2;

    if (this->heap[parentIndex] < this->heap[index])
    {
        std::swap(this->heap[parentIndex], this->heap[index]);
        heapifyUp(parentIndex);
    }
}

template <typename T>
void BinaryHeap<T>::heapifyDown(int index)
{
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex >= this->size)
        return;

    int maxIndex = index;

    if (this->heap[maxIndex] < this->heap[leftChildIndex])
        maxIndex = leftChildIndex;

    if (rightChildIndex < this->size && this->heap[maxIndex] < this->heap[rightChildIndex])
        maxIndex = rightChildIndex;

    if (maxIndex != index)
    {
        std::swap(this->heap[maxIndex], this->heap[index]);
        heapifyDown(maxIndex);
    }
}

template <typename T>
bool BinaryHeap<T>::isFull()
{
    return size == capacity;
}

template <typename T>
bool BinaryHeap<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
int BinaryHeap<T>::getSize()
{
    return this->size;
}

template <typename T>
void BinaryHeap<T>::insert(T data)
{
    if (isFull())
        throw std::runtime_error("Heap is Full.");

    this->heap[size] = data;
    heapifyUp(size);
    size++;
}

template <typename T>
T BinaryHeap<T>::extractMax()
{
    if (isEmpty())
        throw std::runtime_error("Heap is Empty.");

    T max = this->heap[0];
    std::swap(this->heap[0], this->heap[--size]);
    heapifyDown(0);

    return max;
}

template <typename T>
T BinaryHeap<T>::getMax()
{
    if (isEmpty())
        throw std::runtime_error("Heap is Empty.");

    return this->heap[0];
}

template <typename T>
void BinaryHeap<T>::print()
{
    if (isEmpty())
    {
        std::cout << "Heap is Empty." << std::endl;
        return;
    }

    for (int i = 0; i < size; i++)
        std::cout << this->heap[i] << " ";
    std::cout << std::endl;
}