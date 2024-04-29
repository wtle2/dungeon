#include "enemy.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_PURPLE  "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
int treasureAmount = 1000;
void Enemy::combat(Player& player) {
   // std::cout << "You encountered a " << getType() << "!" << std::endl;  //might be extra

    // Start combat loop
    while (player.getHealth() > 0 && getHealth() > 0) {
        // Player's turn
        std::cout << "Your turn:" << std::endl;
        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Run away" << std::endl;
        std::cout << "3. Heal" << std::endl;

        int choice;
        std::cin >> choice;
                if (choice == 1) {
            player.attackEnemy(*this);
        } else if (choice == 2) {
            std::cout << "You ran away extremely fast." << std::endl;
            break;

        } else if(choice == 3){
            srand(static_cast<unsigned>(time(nullptr)));
            int healAmount = rand() % 21 + 10;
            player.updateHealth(healAmount);
            attackPlayer(player);
            std::cout << "You healed " << healAmount << " hitpoints using magic" << std::endl;
            std::cout << ANSI_COLOR_WHITE << "Player Health: [" <<  ANSI_COLOR_RESET << ANSI_COLOR_GREEN << player.getHealth() << ANSI_COLOR_WHITE << "]" <<ANSI_COLOR_RESET << ANSI_COLOR_WHITE << "  Enemy Health: [" << ANSI_COLOR_RESET << ANSI_COLOR_RED << getHealth() << ANSI_COLOR_WHITE << "]" << std::endl;

            continue;
        }

        else {
            std::cout << "Invalid choice. Please choose again." << std::endl;
            continue; // Restart the loop to prompt for a valid choice
        }

        // Check if enemy is defeated after player's turn
        if (getHealth() <= 0) {
            std::cout << "You defeated the " << getType() << "!" << std::endl;

            std::cout << "You stole " << treasureAmount << " treasures!" << std::endl;
            player.addTreasure(treasureAmount);


            break; // Combat ends if enemy is defeated
        }

        // Enemy's turn
        attackPlayer(player);

        // Check if player is defeated after enemy's turn
        if (player.getHealth() <= 0) {
            std::cout << "You were defeated by the " << getType() << "!" << std::endl;

            break; // Combat ends if player is defeated  ////////// add on to quit the game and displauy a screen or smth that u lost
        }
        // std::cout << "Your Health: " << player.getHealth() << ", Enemy Health: " << getHealth() << std::endl;
        std::cout << ANSI_COLOR_WHITE << "Player Health: [" <<  ANSI_COLOR_RESET << ANSI_COLOR_GREEN << player.getHealth() << ANSI_COLOR_WHITE << "]" <<ANSI_COLOR_RESET << ANSI_COLOR_WHITE << "  Enemy Health: [" << ANSI_COLOR_RESET << ANSI_COLOR_RED << getHealth() << ANSI_COLOR_WHITE << "]" << std::endl;
    }
  
}