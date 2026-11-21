#include "GameManager.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() : player("Hero", 100, 15), isRunning(true) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void GameManager::start() {
    std::cout << "=== Turn-Based RPG Started ===" << std::endl;
    while (isRunning) {
        showMenu();
        int choice = getValidatedInput();
        processChoice(choice);
    }
}

void GameManager::showMenu() {
    std::cout << "\n--- Main Menu ---\n";
    std::cout << "1. Start Battle Loop\n";
    std::cout << "2. View Player Stats\n";
    std::cout << "3. Exit Game\n";
    std::cout << "4. Scan Planetary Hazards\n";
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
            if (!(std::cin >> action)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid action. Try again.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    case 4:
        triggerEnvironmentalHazard();
        break;
    default:
        std::cout << "Invalid selection. Try again.\n";
        break;
    }
}

void GameManager::triggerEnvironmentalHazard() {
    int roll = std::rand() % 4;
    std::cout << "\n=== Planetary Environmental Scan ===\n";
    if (roll == 0) {
        std::cout << "Dust Storm! Low visibility slows sensor sweeps, but hull remains intact.\n";
    }
    else if (roll == 1) {
        std::cout << "Acid Rain / Radiation Surge! You take 10 damage.\n";
        player.takeDamage(10);
        std::cout << player.getName() << " HP is now " << player.getHealth() << ".\n";
    }
    else if (roll == 2) {
        std::cout << "Seismic Tremor! Ground shifts beneath you for 5 damage.\n";
        player.takeDamage(5);
        std::cout << player.getName() << " HP is now " << player.getHealth() << ".\n";
    }
    else {
        std::cout << "Surface conditions are calm. No environmental hazards detected.\n";
    }
}

int GameManager::getValidatedInput() {
    std::string input;
    while (true) {
        std::cout << "Enter choice: ";
        std::getline(std::cin, input);
        try {
            // Convert string to integer safely.
            return std::stoi(input);
        }
        catch (...) {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
}