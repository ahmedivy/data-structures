#include <iostream>
#include <string>

#include "solvemaze.h"

int main(int argc, char* argv[]) 
{
    // if (argc < 2) 
    // {
    //     std::cerr << "Usage: " << argv[0] << " <maze file>" << std::endl;
    //     return 1;
    // }

    SolveMaze* solver = new SolveMaze("puzzles/maze2.txt");

    // Print the maze before solving it
    std::cout << "Maze before solving: " << std::endl << std::endl;
    solver->printMaze();

    // Use the solver object to solve the maze

    solver->solve();
    
    // Print the maze after solving it
    std::cout << "Maze after solving: " << std::endl << std::endl;
    solver->printMaze();

    delete solver;

    return 0;
}
