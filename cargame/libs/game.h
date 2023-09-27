#ifndef GAME_H
#define GAME_H

class Game
{
    int score = 0;

public:
    void play();
private:
    void render(int max);
};

#endif