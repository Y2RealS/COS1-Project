#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Enemy(std::string enemyName, int enemyHealth, int enemyAttack);

    std::string getName() const;
    int getHealth() const;
    void takeDamage(int amount);
    bool isAlive() const;
    int getAttackPower() const;
};

#endif