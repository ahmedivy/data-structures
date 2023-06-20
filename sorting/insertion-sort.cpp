#include <iostream>

void sort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            std::swap(array[j], array[j - 1]);
            j--;
        }
    }
}

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int array[] = {2, 9, 3, 7, 4, 0, 1};
    int n = sizeof(array) / sizeof(int);
    print(array, n);
    sort(array, n);
    print(array, n);
}
