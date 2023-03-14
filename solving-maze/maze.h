#pragma once

#include <string>

namespace maze 
{
    class Location
    {
        private:
            int x, y;

        public:
            Location(int x, int y);
            Location(const Location* loc);
            int getX();
            int getY();
            virtual Location* clone() const;
            Location* move(int direction);
            Location* adjacent(int direction);
    };

    class Direction
    {
        private:
            int d;

        public:
            const static int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;
            Direction(int d);
            int getDirection();
    };

    class Maze
    {
        private:
            int m, n;
            int** a;

        public:
            const static int OPEN = 0, WALL = 1, TRIED = 2, PATH = 3;

            Maze(std::string file);
            ~Maze();
            bool isOpen(Location loc);
            void markMoved(Location loc);
            void markTried(Location loc);
            int getHeight();
            int getWidth();
            void print();
    };

    class Rat
    {
        private:
            Maze maze;
            Location loc;
            
        public:
            Rat(Maze maze);
            Location getLocation();
            void setLocation(Location loc);
            bool canMove(int direction);
            bool isOut();
    };
}