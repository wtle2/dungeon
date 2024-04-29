#include "player.h"
#include "enemy.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player() : health(100), treasure(0) {}

Player::Player(int initialHealth) : health(initialHealth), treasure(0) {}

void Player::updateHealth(int amount) {
    health += amount;
    if (health < 0) health = 0; // Ensure health doesn't go below zero
}

void Player::attackEnemy(Enemy& enemy){
    int playerDamage = calculatePlayerDamage();
    std::cout << "You attack the " << enemy.getType() << " and deal " << playerDamage << " damage!" << std::endl;
    enemy.updateHealth(-playerDamage);
}


void Player::addTreasure(int amount) {
    treasure += amount;
}








 /* void Player::encounterEvent() {
    int eventRoll = rand() % 3; // Generate a random number between 0 and 2

    if (eventRoll == 0) {
        cout << "Nothing happened." << endl;
    } else if (eventRoll == 1) {
        cout << "Enemy encountered!" << endl;
        cout << "Do you want to attack the enemy? (1 = Yes, 0 = No): ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            // Player chooses to attack the enemy
            // Example: Reduce enemy's health when attacked
            cout << "You attacked the enemy!" << endl;
        } else {
            // Player chooses to run away
            cout << "You chose to run away!" << endl;
        }
    } else if (eventRoll == 2) {
        // Event: Find treasure
        addTreasure(50); // Example: Increase player's treasure value when finding treasure
        cout << "Player found 50 treasure!" << endl;
    }
}
  */
