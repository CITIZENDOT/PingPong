#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <curses.h>

#include "Ball.h"
#include "Paddle.h"

class GameManager {
private:
    int width, height;
    int scoreA, scoreB;
    const char UP_A = 'w', DOWN_A = 's', UP_B = 'i', DOWN_B = 'k', QUIT = 'q';
    bool quit;
    Ball ball;
    Paddle playerA, playerB;
    std::string BALL_SYMBOL, PLAYER_A_SYMBOL,
        PLAYER_B_SYMBOL, FENCE, EMPTY;

    const std::string NEW_BALL_SYMBOL = "⚽", NEW_PLAYER_A_SYMBOL = "🔰",
                      NEW_PLAYER_B_SYMBOL = "🔰", NEW_FENCE = "⚔";
    const std::string OLD_BALL_SYMBOL = "O", OLD_PLAYER_A_SYMBOL = "█",
                      OLD_PLAYER_B_SYMBOL = "█", OLD_FENCE = "▓";
    const std::string FALLBACK_BALL_SYMBOL = "O", FALLBACK_PLAYER_A_SYMBOL = "I",
                      FALLBACK_PLAYER_B_SYMBOL = "I", FALLBACK_FENCE = "X";
    const int PLAYER_HEIGHT = 4;

    bool in(int low, int value, int high);

public:
    GameManager(int w, int h);
    void scoreUp(Paddle &player);

    void draw();

    void input();

    void logic();

    void run();
};

#endif