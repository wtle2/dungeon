#include <iostream>
#include <cstdlib>
#include <fstream>
#include "player.h"
#include "enemy.h"

int choice;
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_PURPLE  "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
using namespace std;

void playGame(Player& player, int& highestTreasure){
int playerDirection = 0; // 0 = straight, 1 = left, 2 = right
int traversalCount = 0; // Counter for traversals

bool generateEvent = false;
bool hasWon = false;
while (true) {
    // Get player's traversal action
    cout << "Enter your movement (0 = straight, 1 = left, 2 = right): ";
    int action;
    cin >> action;

    // Update player direction based on the action
    if (action == 0) {
        playerDirection = 0;
    } else if (action == 1) {
        playerDirection = 1;
    } else if (action == 2) {
        playerDirection = 2;
    } else if(action ==3 ){
        saveGame(player, highestTreasure);
    }

    else {
        cout << "Invalid action! Try again." << endl;
        continue;
    }

    // Increment the traversal count
    traversalCount++;

    cout << ANSI_COLOR_WHITE << "Player Health: [" <<  ANSI_COLOR_RESET << ANSI_COLOR_GREEN << player.getHealth() << ANSI_COLOR_WHITE "]" ANSI_COLOR_RESET << endl;

    cout << ANSI_COLOR_WHITE << "Treasure collected: [" <<  ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << player.getTreasure() << ANSI_COLOR_WHITE "]" ANSI_COLOR_RESET << endl;

            // Generate an event after every traversal if it's time for an event
            if (generateEvent) {
                int eventRoll = rand() % 2; // Generate a random number between 0 and 2
                                                // Handle the event
                if (eventRoll == 0) {
                    cout << "Treasure found!" << endl;

                    cout << "You found treasure!" << endl;
                    cout << "Do You want to collect it? (1 - yes, 0 = no)" << endl;
                    cin >> choice;
                    if (choice == 1){
                        int treasureAmount = 1000;
                        player.addTreasure(treasureAmount);
                        if(player.getTreasure() > highestTreasure){
                            highestTreasure = player.getTreasure();
                        }


                    }
                }else if (eventRoll == 1) {
                    int enemyType = Enemy::getRandomNumber(1, 3); // Generate a random number between 1 and 3
                    Enemy* enemy;

                     if (enemyType == 1) {
                        enemy =  new Goblin();
                        } else if (enemyType == 2) {
                        enemy =  new Zombie();
                        } else {
                        enemy =  new Spider();
                        }
                        enemy->encounterMessage(); //player inside

                    enemy ->combat(player);

                }
                if(!hasWon && player.getTreasure() >= 2000){
                    hasWon = true;
                    cout << ANSI_COLOR_CYAN "Congratulations you wont the game!" << ANSI_COLOR_RESET << endl;
                    cout << "Do you want to continue playing? (1 - yes, 0 = no)" << endl;
                    cin >> choice;
                    if(choice == 0){
                        cout << ANSI_COLOR_GREEN "THANKS FOR PLAYING ;)" << ANSI_COLOR_RESET << endl;
                        break;
                    }
                }

                generateEvent = false; // Prevent further event generation until the next traversal
            } 
            else
            {
                cout << "Nothing happened.." << endl;
                generateEvent = true;
            }
        }
}