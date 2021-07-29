#include "GameObject.h"

GameObject::GameObject(int posX, int posY, std::string Type = "GameObject") {
    x = originalX = posX;
    y = originalY = posY;
    type = Type;
}
int GameObject::getX() { return x; }
int GameObject::getY() { return y; }
void GameObject::reset() {
    x = originalX;
    y = originalY;
}
std::ostream &operator<<(std::ostream &o, GameObject G) {
    o << G.type << " [" << G.x << ", " << G.y << "]\n";
    return o;
}
