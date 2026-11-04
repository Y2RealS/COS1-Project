#include "../include/Player.h"
#include <iostream>

Player::Player(std::string playerName, int hp, int atk)
    : name(playerName), health(hp), maxHealth(hp), attackPower(atk) {
}

std::string Player::getName() const { return name; }
int Player::getHealth() const { return health; }
bool Player::isAlive() const { return health > 0; }

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
}