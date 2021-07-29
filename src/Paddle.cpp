#include "Paddle.h"

#include <random>
#include <sstream>

Paddle::Paddle() : GameObject(0, 0, "Paddle") { id = Paddle::generateUUID(); }

Paddle::Paddle(int posX, int posY) : GameObject(posX, posY, "Paddle") {
    id = generateUUID();
}

std::string Paddle::generateUUID() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::stringstream ss;
    int i;
    ss << std::hex;
    for (i = 0; i < 8; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 4; i++) {
        ss << dis(gen);
    }
    ss << "-4";
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    ss << dis2(gen);
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 12; i++) {
        ss << dis(gen);
    };
    return ss.str();
}

void Paddle::moveUp() { y--; }
void Paddle::moveDown() { y++; }
std::ostream &operator<<(std::ostream &o, Paddle P) {
    o << "Paddle[" << P.id << "][" << P.x << ", " << P.y << "]\n";
    return o;
}
bool Paddle::operator==(Paddle p) { return id == p.id; }
