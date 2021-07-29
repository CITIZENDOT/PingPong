#include "GameManager.h"

bool GameManager::in(int low, int value, int high) {
    return (low <= value) && (value <= high);
}

GameManager::GameManager(int w, int h) {
    width = w;
    height = h;
    srand(time(0));
    quit = false;
    scoreA = scoreB = 0;
    ball = Ball(w / 2, h / 2);
    playerA = Paddle(1, h / 2 + 1);
    playerB = Paddle(w - 2, h / 2 + 1);
    printw("Is this character appearing as Football emoji? [Y/n]:  %s  ", NEW_BALL_SYMBOL.data());
    int input = getch();
    if (input == 'Y' || input == 'y') {
        BALL_SYMBOL = NEW_BALL_SYMBOL;
        PLAYER_A_SYMBOL = NEW_PLAYER_A_SYMBOL;
        PLAYER_B_SYMBOL = NEW_PLAYER_B_SYMBOL;
        FENCE = NEW_FENCE;
    } else {
        BALL_SYMBOL = OLD_BALL_SYMBOL;
        PLAYER_A_SYMBOL = OLD_PLAYER_A_SYMBOL;
        PLAYER_B_SYMBOL = OLD_PLAYER_B_SYMBOL;
        FENCE = OLD_FENCE;
    }
    EMPTY = " ";
}

void GameManager::scoreUp(Paddle &player) {
    if (player == playerA)
        scoreA++;
    else if (player == playerB)
        scoreB++;
    ball.reset();
    playerA.reset();
    playerB.reset();
}

void GameManager::draw() {
    clear();
    for (int i = 0; i < width + 2; i++)
        printw(FENCE.data());
    printw("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int ballX = ball.getX(), ballY = ball.getY();
            int playerAX = playerA.getX(), playerAY = playerA.getY();
            int playerBX = playerB.getX(), playerBY = playerB.getY();

            if (j == 0)
                printw(FENCE.data());

            if (ballX == j && ballY == i) {
                printw(BALL_SYMBOL.data());
                if (BALL_SYMBOL == NEW_BALL_SYMBOL)
                    j += 1;
            } else if (playerAX == j && in(playerAY, i, playerAY + PLAYER_HEIGHT - 1)) {
                printw(PLAYER_A_SYMBOL.data());
                if (PLAYER_A_SYMBOL == NEW_PLAYER_A_SYMBOL)
                    j += 1;
            } else if (playerBX == j && in(playerBY, i, playerBY + PLAYER_HEIGHT - 1)) {
                printw(PLAYER_B_SYMBOL.data());
                if (PLAYER_B_SYMBOL == NEW_PLAYER_B_SYMBOL)
                    j += 1;
            } else
                printw(EMPTY.data());

            if (j == width - 1)
                printw(FENCE.data());
        }
        printw("\n");
    }

    for (int i = 0; i < width + 2; i++)
        printw(FENCE.data());
    printw("\n");
    printw("ScoreA: %d\n", scoreA);
    printw("ScoreB: %d\n", scoreB);
    refresh();
}

void GameManager::input() {
    ball.move();
    int playerAY = playerA.getY();
    int playerBY = playerB.getY();

    timeout(75);
    int ch = getch();
    if (ch == UP_A && (playerAY - 1) > 0)
        playerA.moveUp();
    else if (ch == UP_B && (playerBY - 1) > 0)
        playerB.moveUp();
    else if (ch == DOWN_A && (playerAY + 1) < height)
        playerA.moveDown();
    else if (ch == DOWN_B && (playerBY + 1) < height)
        playerB.moveDown();

    if (ball.getDirection() == STOP)
        ball.randomDirection();
    if (ch == QUIT)
        quit = true;
}

void GameManager::logic() {
    int ballX = ball.getX(), ballY = ball.getY();
    int playerAX = playerA.getX(), playerAY = playerA.getY();
    int playerBX = playerB.getX(), playerBY = playerB.getY();

    // Left Paddle
    for (int i = 0; i < PLAYER_HEIGHT; i++)
        if (ballX == (playerAX + 1) && ballY == (playerAY + i))
            ball.changeDirection((Direction)((rand() % 3) + 4));

    // Right Paddle
    for (int i = 0; i < PLAYER_HEIGHT; i++)
        if (ballX == (playerBX - 1) && ballY == (playerBY + i))
            ball.changeDirection((Direction)((rand() % 3) + 1));

    // Bottom Wall
    if (ballY == (height - 1))
        ball.changeDirection(ball.getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

    // Top Wall
    if (ballY == 0)
        ball.changeDirection(ball.getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

    // Right wall
    if (ballX == (width - 1)) {
        if (in(playerBY, ballY, playerBY + PLAYER_HEIGHT - 1))
            scoreUp(playerB);
        else
            scoreUp(playerA);
    }

    // Left wall
    if (ballX == 0) {
        if (in(playerAY, ballY, playerAY + PLAYER_HEIGHT - 1))
            scoreUp(playerA);
        else
            scoreUp(playerB);
    }
}

void GameManager::run() {
    while (!quit) {
        draw();
        input();
        logic();
    }
}
