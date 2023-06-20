#include <iostream>

void sort(int array[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        std::swap(array[i], array[min]);
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
