#include <iostream>
#include <string>
#include <cassert>

#include "Maze.h"

class TestMaze
{
    public:
        static void run()
        {
            Maze maze("puzzles/maze3.txt");

            assert(maze.getHeight() == 16);
            std::cout << "Pass Maze Test 1" << std::endl;

            assert(maze.getWidth() == 29);
            std::cout << "Pass Maze Test 2" << std::endl;
        }
};