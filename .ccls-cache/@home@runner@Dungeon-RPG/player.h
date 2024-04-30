#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>

class Enemy; //forward declaration

class Player { //class player
private:
    int health;
    int treasure;

public:
    Player();
    Player(int initialHealth);


    int calculatePlayerDamage() const{
        return rand() % 50 + 10;
    }
    void attackEnemy(Enemy& enemy);
//all player functions declared
    void updateHealth(int amount);

    int getHealth() const{return health;}
// Inside the Player class
void setHealth(int newHealth) {
    health = newHealth;
}

void setTreasure(int newTreasure) {
    treasure = newTreasure;
}

    int getTreasure() const{ return treasure;}

    void addTreasure(int amount);

    void showStats();

};

#endif // PLAYER_H