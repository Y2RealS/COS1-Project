#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
private:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int weaponPower = 1;
    int shieldPower = 1;
public:
    Player(std::string playerName = "Hero", int hp = 100, int atk = 15);

    std::string getName() const;
    int getHealth() const;
    int getAttackPower() const;
    bool isAlive() const;

    void takeDamage(int amount);
    void heal(int amount);
    void allocatePower(int amount);
};

#endif