#pragma once

#include <string>
#include <iostream>

class Employee
{
public:
    int id;
    std::string name;

    Employee() = default;

    Employee(int id, std::string name)
    {
        this->id = id;
        this->name = name;
    }

    void print()
    {
        std::cout << this->id << ". " << this->name << std::endl;
    }

    bool equal(Employee* other)
    {
        return id == other->id;
    }
};
