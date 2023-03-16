#include <iostream>
#include <string>

#include "Location.h"
#include "Direction.h"

Location::Location(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Location::getX()
{
    return x;
}

int Location::getY()
{
    return y;
}

void Location::move(int direction)
{
    switch(direction)
    {
        case Direction::NORTH:
            --y;
            break;
        case Direction::EAST:
            ++x;
            break;
        case Direction::SOUTH:
            ++y;
            break;
        case Direction::WEST:
            --x;
            break;
    }
}

Location* Location::adjacent(int direction)
{
    switch(direction)
    {
        case Direction::NORTH:
            return new Location(x, y-1);
        case Direction::EAST:
            return new Location(x+1, y);
        case Direction::SOUTH:
            return new Location(x, y+1);
        case Direction::WEST:
            return new Location(x-1, y);
    }
    return NULL;
}

void Location::print()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

bool Location::equals(Location location)
{
    return x == location.getX() && y == location.getY();
}

Location* Location::clone()
{
    return new Location(x, y);
}