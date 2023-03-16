#pragma once

class Location
{
    private:
        int x;
        int y;
    public:
        Location(int x, int y);
        int getX();
        int getY();
        bool equals(Location location);
        void move(int direction);
        Location* adjacent(int direction);
        void print();
        Location* clone();
};