#include <iostream>
#include <string>

#include "LinkedList.h"
#include "CircularLinkedList.h"

using namespace std;

int main()
{
    // Copy Function Test
    LinkedList<int>* list = new LinkedList<int>();

    cout << "Inserts 4 in list" << endl;
    list->insertBack(4);
    cout << "Inserts 6 in list" << endl;
    list->insertBack(6);
    cout << "Inserts 8 in list" << endl;
    list->insertBack(8);
    cout << "List: " << endl;
    list->display();

    LinkedList<int>* copy = list->copy();
    cout << "Copied List: " << endl;
    copy->display();

    cout << "Delete last element from copied list" << endl;
    copy->deleteBack();

    cout << "List: " << endl;
    list->display();
    cout << "Copied List: " << endl;
    copy->display();


    // Concat Function Test
    LinkedList<int>* concatenatedList = list->concat(copy);
    cout << "Concatenated List: " << endl;
    concatenatedList->display();

    // Replace Function Test
    cout << "Replace first index value with 10" << endl;
    concatenatedList->replace(1, 10);
    cout << "Concatenated List: " << endl;
    concatenatedList->display();

    // Second to Last Function Test
    cout << "Second to last element in list: " << concatenatedList->secondToLast() << endl;

    // Rotate Function Test
    cout << "Rotate list by 2" << endl;
    concatenatedList->rotate(2);
    cout << "Concatenated List: " << endl;
    concatenatedList->display();

    // Size Function Test
    CircularLinkedList<int>* circularList = new CircularLinkedList<int>();
    cout << "Size of circular list: " << circularList->getSize() << endl;
    cout << "Inserts 4 in circular list" << endl;
    circularList->insertFront(4);
    cout << "Inserts 6 in circular list" << endl;
    circularList->insertFront(6);
    cout << "Inserts 8 in circular list" << endl;
    circularList->insertFront(8);
    cout << "Size of circular list: " << circularList->getSize() << endl;
    cout << "Circular List: " << endl;
    circularList->display();
}

