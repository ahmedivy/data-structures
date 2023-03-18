#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "maze.h"
#include "location.h"
#include "rat.h"
#include "direction.h"

Maze::Maze(std::string fileName)
{
    std::ifstream infile(fileName);
    if (!infile)
    {
        std::cerr << "Error: could not open file " << fileName << std::endl;
        exit(1);
    }

    // Read the number of rows and columns from first two lines of file
    infile >> rows >> cols;
    if (rows <= 0 || cols <= 0)
    {
        std::cerr << "Error: invalid number of rows or columns in file " << fileName << std::endl;
        exit(1);
    }

    // Read the maze data from the file
    mazeArray.resize(rows, std::vector<int>(cols));

    startPoint = NULL;
    endPoint = NULL;

    std::string line;
    for (int i = 0; i < rows; i++)
    {
        infile >> line;
        for (int j = 0; j < cols; j++)
        {
            if (line[j] == 'A')
            {
                startPoint = new Location(j, i);
            }
            else if (line[j] == 'B')
            {
                endPoint = new Location(j, i);
            }
            mazeArray[i][j] = (line[j] == '1' ? 1 : 0);
        }
    }
    infile.close();

    if (!startPoint)
        startPoint = new Location(0,1);
    if (!endPoint)
        endPoint = new Location(cols - 1, rows - 2);
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
    catch(const std::out_of_range& e)
    {
        return false;
    }
    
}

void Maze::markMoved(Location* location)
{
    mazeArray.at(location->getY()).at(location->getX()) = PATH;
}

void Maze::markTried(Location* location)
{
    mazeArray.at(location->getY()).at(location->getX()) = TRIED;
}

int Maze::getHeight()
{
    return rows;
}

int Maze::getWidth()
{
    return cols;
}

Location* Maze::getStartPoint()
{
    return startPoint;
}

Location* Maze::getEndPoint()
{
    return endPoint;
}

void Maze::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            switch(mazeArray[i][j])
            {
                case OPEN:
                    std::cout << " ";
                    break;
                case WALL:
                    std::cout << "#";
                    break;
                case PATH:
                    std::cout << "o";
                    break;
                case TRIED:
                    std::cout << "?";
                    break;
            }
        }
        std::cout << std::endl;
    }
}
