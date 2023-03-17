#include <iostream>
#include <string>

#include "Maze.h"
#include "Location.h"
#include "Rat.h"

Rat::Rat(Maze* maze) : maze(maze)
{
    location = maze->getStartPoint();
}

Location* Rat::getLocation()
{
    return new Location(location->getX(), location->getY());
}

void Rat::setLocation(Location* location)
{
    this->location = location;
}

bool Rat::canMove(int direction)
{
    Location* adjacent = location->adjacent(direction);
    if (adjacent->getX() < 0 || adjacent->getX() >= maze->getWidth())
        return false;
    bool canMove = maze->isOpen(*adjacent);
    delete adjacent;
    return canMove;
}

void Rat::move(int direction)
{

    location->move(direction);
    maze->markMoved(location);
}

bool Rat::isOut()
{
    return maze->getEndPoint()->equals(*location);
}
