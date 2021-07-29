#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <string>

enum Direction {
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6
};

class GameObject {
protected:
    int x, y, originalX, originalY;
    std::string type;

public:
    GameObject(int posX, int posY, std::string Type);
    int getX();
    int getY();
    void reset();
    friend std::ostream &operator<<(std::ostream &o, GameObject G);
};

#endif