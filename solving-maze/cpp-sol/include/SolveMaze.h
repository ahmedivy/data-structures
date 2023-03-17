#pragma once

#include <iostream>
#include <string>
#include <stack>

#include "Rat.h"
#include "Maze.h"
#include "Location.h"
#include "Direction.h"

class SolveMaze
{
    private:
        Maze* maze;
        Rat* rat;
        std::stack<Location*> pathStack;
    public:
        SolveMaze(const char* mazeFile);
        void solve();
        void printMaze();
};
