#include <iostream>
#include <cmath>

#include "player.h"

Player::Player(int roadWidth) {
    playerPositionOrigin.x = std::floor(roadWidth / 2);
    playerPosition.x = playerPositionOrigin.x;
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

void Player::revive() {
    isAlive = true;
    playerPosition.x = playerPositionOrigin.x;
}

bool Player::is_player_alive() {
    return isAlive;
}

void Player::set_position(int newPosition) {
    playerPosition.x = newPosition;
}