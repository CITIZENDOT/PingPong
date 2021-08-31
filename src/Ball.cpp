import Balls;


Ball::Ball() : GameObject(0, 0, "Ball") { direction = STOP; }

Ball::Ball(int posX, int posY) : GameObject(posX, posY, "Ball") {
    direction = STOP;
}
void Ball::reset() {
    GameObject::reset();
    direction = STOP;
}
void Ball::randomDirection() { direction = (Direction)((rand() % 6) + 1); }
void Ball::changeDirection(Direction d) { direction = d; }
Direction Ball::getDirection() { return direction; }
void Ball::move() {
    switch (direction) {
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--;
        y--;
        break;
    case DOWNLEFT:
        x--;
        y++;
        break;
    case UPRIGHT:
        x++;
        y--;
        break;
    case DOWNRIGHT:
        x++;
        y++;
        break;
    default:
        break;
    }
}
std::ostream &operator<<(std::ostream &o, Ball B) {
    o << "Ball [" << B.x << ", " << B.y << "][" << B.direction << "]\n";
    return o;
}
