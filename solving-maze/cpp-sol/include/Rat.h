#pragma once

#include "Maze.h"
#include "Location.h"

class Rat
{
    private:
        Maze* maze;
        Location* location;
    public:
        Rat(Maze* maze);
        Location* getLocation();
        void setLocation(Location* location);
        bool canMove(int direction);
        void move(int direction);
        bool isOut();
};

