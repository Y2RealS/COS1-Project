#include "Enemy.h"
#include <string>
#include <iostream>

Enemy::Enemy(std::string enemyName, int enemyHealth, int enemyAttack)
    : name(enemyName), health(enemyHealth), attackPower(enemyAttack) {
}

std::string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getAttackPower() const { return attackPower; }

void Enemy::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

bool Enemy::isAlive() const { return health > 0; }