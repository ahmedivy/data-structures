#include <iostream>
#include <string>
#include <stack>

#include "Rat.h"
#include "Maze.h"
#include "Location.h"
#include "Direction.h"
#include "SolveMaze.h"


SolveMaze::SolveMaze(const char* mazeFile)
{
    maze = new Maze(mazeFile);
    rat = new Rat(maze);
    pathStack = std::stack<Location>();
    solved = false;
}

bool SolveMaze::isSolved()
{
    return solved;
}

void SolveMaze::printMaze()
{
    maze->print();
}


void SolveMaze::solve()
{
    while(!rat->isOut())
    {
        
    }
}

