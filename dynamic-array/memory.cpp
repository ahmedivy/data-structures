#include <iostream>

using namespace std;

int main() {
    const int n = 5;

    // dynamically allocate memory for an array of n integers
    int* arr_heap = new int[n];

    // allocate memory for an array of n integers on the stack
    int arr_stack[n];

    // get values for both arrays
    for (int i = 0; i < n; i++) {
        arr_heap[i] = i + 1;
        arr_stack[i] = arr_heap[i];
    }

    // display the values and memory addresses of the heap array elements
    cout << "The heap array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr_heap[i] << " (at " << &arr_heap[i] << ") ";
    }
    cout << endl;

    // display the values and memory addresses of the stack array elements
    cout << "The stack array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr_stack[i] << " (at " << &arr_stack[i] << ") ";
    }
    cout << endl;

    // Print Findings
    cout << "The heap array is stored at " << arr_heap << endl;
    cout << "The stack array is stored at " << arr_stack << endl;
    cout << "The heap array is " 
            << (arr_heap < arr_stack ? "less than" : "greater than") 
            << " the stack array" << endl;

    // deallocate the dynamically allocated memory
    delete[] arr_heap;

    return 0;
}
