#ifndef PADDLE_H
#define PADDLE_H
#include <iostream>
#include <string>

#include "GameObject.h"

class Paddle : public GameObject {
private:
    std::string id;
    std::string generateUUID();

public:
    Paddle();
    Paddle(int posX, int posY);
    void moveUp();
    void moveDown();
    friend std::ostream &operator<<(std::ostream &o, Paddle P);
    bool operator==(Paddle p);
};

#endif