#pragma once

#include <vector>
#include <string>

#include "Location.h"

class Maze
{
    private:
        int rows;
        int cols;
        Location* startPoint;
        Location* endPoint;
        std::vector<std::vector<int>> mazeArray;
    public:
        const static int OPEN = 0, WALL = 1, TRIED = 2, PATH = 3;
        Maze(std::string fileName);
        ~Maze();
        bool isOpen(Location location);
        void markMoved(Location* location);
        void markTried(Location* location);
        int getHeight();
        int getWidth();
        Location* getStartPoint();
        Location* getEndPoint();
        void print();
};