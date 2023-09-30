#ifndef GAME_H
#define GAME_H

class Game
{
    int score = 0;

public:
    void play();

private:
    void render(bool *mainLoop);
};

#endif