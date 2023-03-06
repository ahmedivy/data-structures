#include <iostream>
#include "stack.h"

using namespace std;

void printMenu();

int main()
{
    printMenu();

    return 0;
}

void printMenu()
{
    Stack<int> s(30);
    int choice;
    int data;
    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            cout << "Popped : " << s.pop() << endl;
            break;
        case 3:
            cout << "Stack:" << s.display() << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
}
