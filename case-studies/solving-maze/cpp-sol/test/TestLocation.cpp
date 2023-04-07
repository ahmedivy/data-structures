#include <iostream>
#include <string>
#include <cassert>

#include "Location.h"
#include "Direction.h"

class TestLocation
{
    public:
        static void run()
        {
            Location loc(1, 2);
            assert(loc.getX() == 1);
            assert(loc.getY() == 2);
            std::cout << "Pass Location Test 1" << std::endl;

            loc.move(Direction::NORTH);
            assert(loc.getX() == 1);
            assert(loc.getY() == 1);
            std::cout << "Pass Location Test 2" << std::endl;

            loc.move(Direction::EAST);
            assert(loc.getX() == 2);
            assert(loc.getY() == 1);
            std::cout << "Pass Location Test 3" << std::endl;

            loc.move(Direction::SOUTH);
            assert(loc.getX() == 2);
            assert(loc.getY() == 2);
            std::cout << "Pass Location Test 4" << std::endl;

            loc.move(Direction::WEST);
            assert(loc.getX() == 1);
            assert(loc.getY() == 2);
            std::cout << "Pass Location Test 5" << std::endl;
        }
};