#include <iostream>
#include <list>

int main()
{
    std::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);

    std::list<int>::iterator it = list.begin();
    std::advance(it, 5);
    std::cout << *it << std::endl;

    return 0;
}