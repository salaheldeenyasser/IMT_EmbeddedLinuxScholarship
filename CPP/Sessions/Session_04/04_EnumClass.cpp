#include <iostream>


enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};


void printDirection(Direction direction) {
    switch(direction) {
        case Direction::NORTH:
            std::cout << "Direction: NORTH" << std::endl;
            break;
        case Direction::EAST:
            std::cout << "Direction: EAST" << std::endl;
            break;
        case Direction::SOUTH:
            std::cout << "Direction: SOUTH" << std::endl;
            break;
        case Direction::WEST:
            std::cout << "Direction: WEST" << std::endl;
            break;
    }
}


int main() {
    Direction direction = Direction::EAST;
    printDirection(direction);
    return 0;
}