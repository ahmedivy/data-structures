#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    // Declare a function pointer that takes two integers and returns an integer
    int (*pFunc)(int, int);

    // Initialize the function pointer to point to the "add" function
    pFunc = &add;

    // Use the function pointer to call the "add" function
    int result = (*pFunc)(2, 3);
    std::cout << "Result of add function: " << result << std::endl;

    // Change the function pointer to point to the "subtract" function
    pFunc = &subtract;

    // Use the function pointer to call the "subtract" function
    result = (*pFunc)(5, 2);
    std::cout << "Result of subtract function: " << result << std::endl;

    return 0;
}
