#include <iostream>
#include <vector>

struct Entity
{
    int x, y;

    int* getArray()
    {
        return &x;
    }
};

inline void printHello()
{
    std::cout << "Hello" << std::endl;
}

int main()
{
    int a = 50;
    double b = *(double *)&a;

    std::cout << b << std::endl;

    Entity ent = {23, 67};
    int *arr = ent.getArray();
    std::cout << arr[0] << "," << arr[1] << std::endl;
    arr[1] = 68;
    std::cout << ent.x << "," << ent.y << std::endl;

    printHello();
    return 0;
}
