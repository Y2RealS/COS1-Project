#include "../include/GameManager.h"
#include "Enemy.h"
#include <iostream>

GameManager::GameManager() : player("Hero", 100, 15), isRunning(true) {}

void GameManager::start() {
    std::cout << "=== Turn-Based RPG Started ===" << std::endl;
    while (isRunning) {
        showMenu();
        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        processChoice(choice);
    }
}

void GameManager::showMenu() {
    std::cout << "\n--- Main Menu ---\n";
    std::cout << "1. Start Battle Loop\n";
    std::cout << "2. View Player Stats\n";
    std::cout << "3. Exit Game\n";
}

void GameManager::processChoice(int choice) {
    switch (choice) {
    case 1: {
        std::cout << "\n=== Battle Initiated! ===\n";
        Enemy enemy("Tacit Discord", 50, 10);

        while (player.getHealth() > 0 && enemy.isAlive()) {
            std::cout << "\n" << player.getName() << " HP: " << player.getHealth()
                << " | " << enemy.getName() << " HP: " << enemy.getHealth() << "\n";
            std::cout << "1. Attack\n2. Run\nChoose action: ";

            int action;
            std::cin >> action;

            if (action == 1) {
                // Player attacks enemy
                std::cout << "You attack " << enemy.getName() << " for " << player.getAttackPower() << " damage!\n";
                enemy.takeDamage(player.getAttackPower());

                // Enemy attacks back if alive
                if (enemy.isAlive()) {
                    std::cout << enemy.getName() << " attacks you for " << enemy.getAttackPower() << " damage!\n";
                    player.takeDamage(enemy.getAttackPower());
                }
                else {
                    std::cout << "You defeated " << enemy.getName() << "!\n";
                }
            }
            else {
                std::cout << "You fled from battle!\n";
                break;
            }
        }
        break;
    }
    case 2:
        std::cout << "Player: " << player.getName() << " | HP: " << player.getHealth() << "\n";
        break;
    case 3:
        std::cout << "Exiting game. Goodbye!\n";
        isRunning = false;
        break;
    default:
        std::cout << "Invalid selection. Try again.\n";
        break;
    }
}