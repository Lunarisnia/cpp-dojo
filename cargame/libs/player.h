#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    struct
    {
        int x;
    } playerPosition;

    char playerAvatar = '^';
    char diedAvatar = 'x';
    bool isAlive = true;

public:
    Player(int roadWidth);
    void move_left();
    void move_right();
    char get_avatar();
    int get_position();
    void kill();
    bool is_player_alive();
};

#endif