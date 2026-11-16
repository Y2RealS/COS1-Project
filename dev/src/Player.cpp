#include "../include/Player.h"
#include <iostream>

Player::Player(std::string playerName, int hp, int atk)
    : name(playerName), health(hp), maxHealth(hp), attackPower(atk) {
}

std::string Player::getName() const { return name; }
int Player::getHealth() const { return health; }
int Player::getAttackPower() const {
    return attackPower;
}
bool Player::isAlive() const { return health > 0; }

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
}

void Player::allocatePower(int amount) {
    std::cout << "--- Power Allocation (Available: 3) ---\n";
    std::cout << "1. Allocate to Weapons\n2. Allocate to Shields\nChoice: ";

    if (amount == 1) {
        weaponPower++;
        std::cout << "Weapon power increased! Attack damage boosted.\n";
    }
    else {
        shieldPower++;
        std::cout << "Shield power increased! Incoming damage reduced.\n";
    }
}