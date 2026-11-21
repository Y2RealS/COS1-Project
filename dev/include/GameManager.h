#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"

class GameManager {
private:
    Player player;
    bool isRunning;

    void triggerEnvironmentalHazard();
public:
    GameManager();
    void start();
    void showMenu();
    void processChoice(int choice);
    int getValidatedInput();

};

#endif