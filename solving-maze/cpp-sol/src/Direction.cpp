#include <iostream>

#include "Direction.h"

Direction::Direction(int d)
{
    if (d < 0 || d > 3)
    {
        std::cerr << "Illegal Argument!" << std::endl;
        exit(1);
    }
    this->d = d;
}

int Direction::getDirection()
{
    return d;
}