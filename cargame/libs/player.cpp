#include <iostream>
#include <cmath>

#include "player.h"

Player::Player(int roadWidth) {
    playerPosition.x = std::floor(roadWidth / 2);
    isAlive = true;
}

void Player::move_left() {
    playerPosition.x--;
}

void Player::move_right() {
    playerPosition.x++;
}

char Player::get_avatar() {
    return isAlive ? playerAvatar : diedAvatar;
}

int Player::get_position() {
    return playerPosition.x;
}

void Player::kill() {
    isAlive = false;
}

bool Player::is_player_alive() {
    return isAlive;
}