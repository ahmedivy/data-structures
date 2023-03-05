#include <iostream>
#include <cstdlib>

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Allocate memory for the array using malloc
    int *arr = (int *)malloc(n * sizeof(int));

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = i + 1;
    }

    // Print the elements of the array using pointer arithmetic
    std::cout << "Array elements: ";
    for (int *p = arr; p < arr + n; p++)
    {
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    // Resize the array using realloc
    int m;
    std::cout << "Enter the new size of the array: ";
    std::cin >> m;
    arr = (int *)realloc(arr, m * sizeof(int));

    // Initialize the new elements of the array
    for (int i = n; i < m; i++)
    {
        *(arr + i) = i + 1;
    }

    // Print the elements of the resized array using pointer arithmetic
    std::cout << "Resized array elements: ";
    for (int *p = arr; p < arr + m; p++)
    {
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    // Deallocate memory for the array using free
    free(arr);

    return 0;
}
