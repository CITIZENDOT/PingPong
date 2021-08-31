#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <curses.h>

#include "Ball.h"
#include "Paddle.h"

#define MAKE_STR(x) { (wchar_t)x, 0 }

class GameManager {
private:
    int width, height;
    int scoreA, scoreB;
    const char UP_A = 'w', DOWN_A = 's', UP_B = 'i', DOWN_B = 'k', QUIT = 'q';
    bool quit;
    Ball ball;
    Paddle playerA, playerB;
    std::wstring BALL_SYMBOL, PLAYER_A_SYMBOL,
        PLAYER_B_SYMBOL, FENCE;

    const std::wstring NEW_BALL_SYMBOL          = MAKE_STR(0x26BD), // U+26BD: "⚽"
                       NEW_PLAYER_A_SYMBOL      = MAKE_STR(0x23E9), // U+23E9: "⏩"
                       NEW_PLAYER_B_SYMBOL      = MAKE_STR(0x23EA), // U+23EA: "⏪"
                       NEW_FENCE                = MAKE_STR(0x2694), // U+2694: "⚔"
                       OLD_BALL_SYMBOL          = MAKE_STR(0x004F), // U+004F: "O"
                       OLD_PLAYER_A_SYMBOL      = MAKE_STR(0x2588), // U+2588: "█"
                       OLD_PLAYER_B_SYMBOL      = MAKE_STR(0x2588), // U+2588: "█"
                       OLD_FENCE                = MAKE_STR(0x2593), // U+2593: "▓"
                       FALLBACK_BALL_SYMBOL     = MAKE_STR(0x004F), // U+004F: "O"
                       FALLBACK_PLAYER_A_SYMBOL = MAKE_STR(0x0049), // U+0049: "I"
                       FALLBACK_PLAYER_B_SYMBOL = MAKE_STR(0x0049), // U+0049: "I"
                       FALLBACK_FENCE           = MAKE_STR(0x0058), // U+0058: "X"
                       EMPTY                    = MAKE_STR(0x0020); // U+0020: " "
    const int PLAYER_HEIGHT = 4;

    bool in(int low, int value, int high);

    void printEmoji(const std::wstring& str);

public:
    GameManager(int w, int h);
    void scoreUp(Paddle &player);

    void draw();

    void input();

    void logic();

    void run();
};

#endif
