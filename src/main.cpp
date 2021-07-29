#include "Ball.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Paddle.h"

int main() {
    setlocale(LC_ALL, "");
    initscr();
    int maxWidth, maxHeight;
    getmaxyx(stdscr, maxHeight, maxWidth);
    GameManager G(maxWidth - 10, maxHeight - 10);
    G.run();
    endwin();
    return 0;
}
