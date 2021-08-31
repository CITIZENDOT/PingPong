export module Ball;

#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <string>

#include "GameObject.h"

class Ball : public GameObject {
private:
    Direction direction;

public:
    Ball();
    Ball(int posX, int posY);
    void reset();
    void randomDirection();
    void changeDirection(Direction d);
    Direction getDirection();
    void move();
    friend std::ostream &operator<<(std::ostream &o, Ball B);
};

#endif