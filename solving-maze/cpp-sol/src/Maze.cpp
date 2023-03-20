#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "rat.h"
#include "maze.h"
#include "location.h"

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
            mazeArray[i][j] = ((line[j] == '1' || line[j] == '#') ? 1 : 0);
        }
    }
    infile.close();

    if (!startPoint)
        startPoint = new Location(0, 1);
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
    return startPoint->clone();
}

Location* Maze::getEndPoint()
{
    return endPoint->clone();
}

void Maze::print()
{
    std::string chars[] = {" ", "\u01F759" , "?", "o"};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == getStartPoint()->getX() && i == getStartPoint()->getY())
            {
                std::cout << 'A';
            }
            else if (j == getEndPoint()->getX() && i == getEndPoint()->getY())
            {
                std::cout << 'B';
            }
            else
            {
                std::cout << chars[mazeArray[i][j]][0];
            }
        }
        std::cout << std::endl;
    }
}
