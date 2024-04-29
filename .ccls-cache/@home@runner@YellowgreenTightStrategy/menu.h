#include <iostream>
#include <cstdlib>
#include <fstream>
#include "player.h"
#include "enemy.h"
#include "playGame.h"

using namespace std;

// ANSI escape sequence to clear the screen
#define CLEAR_SCREEN "\033[2J\033[1;1H"

// ANSI color codes
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_PURPLE  "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"









void displayMenu(int& highestTreasure) {
    cout << CLEAR_SCREEN; // Clear the console screen
    cout << ANSI_COLOR_GREEN "========== " << ANSI_COLOR_RESET<< ANSI_COLOR_CYAN << "Cryptic dungeon of death" << ANSI_COLOR_RESET << ANSI_COLOR_GREEN << " ==========" << ANSI_COLOR_RESET<< endl;
    cout << ANSI_COLOR_YELLOW << "Highest treasure value: [" << highestTreasure << "]" << ANSI_COLOR_RESET << endl; // add variable for this
    cout << "1. START NEW GAME" << endl;
    cout << "2. LOAD SAVE FILE" << endl;   // maybe implement difficulty level
    cout << ANSI_COLOR_RED << "3. Exit" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_GREEN << "==============================================" << ANSI_COLOR_RESET << endl;
}