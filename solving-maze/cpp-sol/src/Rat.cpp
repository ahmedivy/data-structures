#include <iostream>
#include <string>

#include "Maze.h"
#include "Location.h"
#include "Rat.h"

Rat::Rat(Maze* maze) : maze(maze), location(new Location(0, 1)) {}

Location* Rat::getLocation()
{
    return location;
}

void Rat::setLocation(Location* location)
{
    this->location = location;
}

bool Rat::canMove(int direction)
{
    Location* adjacent = location->adjacent(direction);
    bool canMove = maze->isOpen(*adjacent);
    delete adjacent;
    return canMove;
}

void Rat::move(int direction)
{
    location->move(direction);
    maze->markMoved(*location);
}

bool Rat::isOut()
{
    return location->getY() == 0;
}

