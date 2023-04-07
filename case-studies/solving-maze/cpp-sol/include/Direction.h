#pragma once

class Direction
{
    private:
        int d;
    public:
        const static int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;
        Direction(int d);
        int getDirection();
};