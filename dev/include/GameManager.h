#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"

class GameManager {
private:
    Player player;
    bool isRunning;

public:
    GameManager();
    void start();
    void showMenu();
    void processChoice(int choice);
};

#endif