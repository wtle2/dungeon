#include "player.h"
#include "enemy.h"
#include <cstdlib>
#include <ctime>

using namespace std;
 //player intialization
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








