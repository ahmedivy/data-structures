#include <iostream>
// #include "queue.h"
#include "dynamic-queue.h"

using namespace std;

void printMenu();

int main()
{
    printMenu();

    return 0;
}

void printMenu()
{
    CircularQueue<int> q;
    int choice;
    int data;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            cout << "Dequeued: " << q.dequeue() << endl;
            break;
        case 3:
            cout << "Queue: ";
            q.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
}