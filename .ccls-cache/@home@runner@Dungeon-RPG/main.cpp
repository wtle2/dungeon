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

bool loadGame(Player& player,int& treasure,int &highestTreasure) {
    ifstream saveFile("save.txt");
    if (saveFile.is_open()) {
        // Load player data
        int health, treasure;
        saveFile >> health >> treasure >> highestTreasure;
      player.setHealth(health);
      player.setTreasure(treasure);
        saveFile.close();
        cout << "Game loaded successfully." << endl;
      return true;
    } else {
        cout << "No saved game found." << endl;
      return false;
    }
}

void displayMenu(int& highestTreasure) {
    cout << CLEAR_SCREEN; // Clear the console screen
    cout << ANSI_COLOR_GREEN "========== " << ANSI_COLOR_RESET<< ANSI_COLOR_CYAN << "Cryptic dungeon of death" << ANSI_COLOR_RESET << ANSI_COLOR_GREEN << " ==========" << ANSI_COLOR_RESET<< endl;
  
    cout << ANSI_COLOR_YELLOW << "Highest treasure value: [" << highestTreasure << "]" << ANSI_COLOR_RESET << endl; // add variable for this
    cout << "1. START NEW GAME" << endl;
    cout << "2. LOAD SAVE FILE" << endl;   // maybe implement difficulty level
    cout << ANSI_COLOR_RED << "3. Exit" << ANSI_COLOR_RESET << endl;
    cout << "4. Instructions" << endl;
    cout << ANSI_COLOR_GREEN << "==============================================" << ANSI_COLOR_RESET << endl;
}

int main() {
  int highestTreasure;
  int treasure;
    int choice;
     Player player(100);
  if (loadGame(player, treasure, highestTreasure)) {
        // A saved game was loaded, so highestTreasure is updated
    } else {
        // No saved game found, highestTreasure remains 0
    }

    do {
        displayMenu(highestTreasure);
        cout << "Enter your choice: ";
        cin >> choice;

        
            if(choice == 1){
                cout << "Starting new game..." << endl;
                deleteSaveFile(player);

                srand((unsigned)time(NULL));  // Seed the random number generator
                  playGame(player,treasure,highestTreasure);
                  
                    }




            else if(choice == 2){
                cout << "You chose Option 2" << endl;
                cout << "Loading save file..." << endl;
                if(loadGame(player, treasure, highestTreasure)){ //loading game
                   playGame(player,treasure, highestTreasure);
                  
                }

               
            
            }
            else if(choice == 3){
                cout << ANSI_COLOR_RED << "Exiting..." << ANSI_COLOR_RESET << endl;
                break;
            }
              else if(choice == 4){
                cout << "Reach 10,000 treasure to win" << endl; //instructions
              }
            else{
                cout << ANSI_COLOR_RED << "Invalid choice. Please try again." << ANSI_COLOR_RESET<< endl;
            }

        
      
        if(choice != 3){
            cout << "Press Enter to continue...";
            cin.ignore(); // Clear the input buffer
            cin.get(); // Wait for Enter key
        }

    }

    while (choice != 3);

        return 0;

}