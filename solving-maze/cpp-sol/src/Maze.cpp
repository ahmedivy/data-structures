#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Maze.h"
#include "Location.h"
#include "Rat.h"
#include "Direction.h"

Maze::Maze(std::string fileName)
{
    std::ifstream infile(fileName);
    if (!infile)
    {
        std::cerr << "Error: could not open file " << fileName << std::endl;
        exit(1);
    }

    infile >> rows >> cols;

    if (rows <= 0 || cols <= 0)
    {
        std::cerr << "Error: invalid number of rows or columns in file " << fileName << std::endl;
        exit(1);
    }

    mazeArray.resize(rows, std::vector<int>(cols));

    std::string line;
    for (int i = 0; i < rows; i++)
    {
        infile >> line;
        for (int j = 0; j < cols; j++)
        {
            mazeArray[i][j] = (line[j] == '0' ? 0 : 1);
        }
    }

    infile.close();
}

Maze::~Maze()
{
    mazeArray.clear();
}

bool Maze::isOpen(Location location)
{
    try
    {
        return mazeArray.at(location.getY()).at(location.getX()) == OPEN;
    }
    catch(const std::exception& e)
    {
        return false;
    }
}

void Maze::markMoved(Location location)
{
    mazeArray.at(location.getY()).at(location.getX()) = PATH;
}

void Maze::markTried(Location location)
{
    mazeArray.at(location.getY()).at(location.getX()) = TRIED;
}

int Maze::getHeight()
{
    return rows;
}

int Maze::getWidth()
{
    return cols;
}

void Maze::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << (mazeArray[i][j] == 0 ? " " : "#");
        }
        std::cout << std::endl;
    }
}