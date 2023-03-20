#include <iostream>
#include <string>
#include <stack>
#include <windows.h>

#include "Rat.h"
#include "Maze.h"
#include "Location.h"
#include "SolveMaze.h"


SolveMaze::SolveMaze(const char* mazeFile)
{
    maze = new Maze(mazeFile);
    rat = new Rat(maze);
    pathStack = std::stack<Location*>();
}

SolveMaze::~SolveMaze()
{
    delete maze;
    delete rat;
}

void SolveMaze::printMaze()
{
    maze->print();
}

void SolveMaze::solve()
{
    maze->markMoved(rat->getLocation());
    bool moved = false;
    while(!rat->isOut())
    {
        moved = false;
        for (int direction = 0; direction < 4; direction++)
        {
            if (rat->canMove(direction))
            {
                pathStack.push(rat->getLocation());
                rat->move(direction);
                moved = true;
                break;
            }
        }
        if (!moved)
        {
            maze->markTried(rat->getLocation());
            if (pathStack.empty())
            {
                std::cout << "No solution found" << std::endl;
                exit(1);
            }
            rat->setLocation(pathStack.top());
            pathStack.pop();
        }
        maze->print();
        Sleep(100);
        system("cls");
    }
    
}

