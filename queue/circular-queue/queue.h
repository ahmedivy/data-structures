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

pu