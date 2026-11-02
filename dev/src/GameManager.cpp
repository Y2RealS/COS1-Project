#include "../include/GameManager.h"
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
    case 1:
        std::cout << "Entering battle loop...\n";
        break;
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