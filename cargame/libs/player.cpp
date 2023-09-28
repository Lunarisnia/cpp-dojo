#include <iostream>
#include <cmath>

#include "player.h"

Player::Player(int roadWidth) {
    // playerPosition.x = std::floor(roadWidth / 2);
    playerPosition.x = 0;
}

void Player::move_left() {
    playerPosition.x--;
}

void Player::move_right() {
    playerPosition.x++;
}

char Player::get_avatar() {
    return playerAvatar;
}

int Player::get_position() {
    return playerPosition.x;
}