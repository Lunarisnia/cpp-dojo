#ifndef GAME_H
#define GAME_H

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESCAPE 27

class Game
{
    int score = 0;

public:
    void play();

private:
    void render();
};

#endif