#include "player.hpp"

int Player::stacksize() {
    return 1;
}

int Player::cardesTaken() {
    return 1;
}

Player::Player() {}

Player::Player(string n) {
    name = n;
}
