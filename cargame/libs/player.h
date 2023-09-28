#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    struct
    {
        int x;
    } playerPosition;

    char playerAvatar = '^';

public:
    Player(int roadWidth);
    void move_left();
    void move_right();
    char get_avatar();
    int get_position();
};

#endif