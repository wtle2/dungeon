#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>

class Enemy;

class Player {
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

    void updateHealth(int amount);

    int getHealth() const{return health;}
// Inside the Player class
void setHealth(int newHealth) {
    health = newHealth;
}

void setTreasure(int newTreasure) {
    treasure = newTreasure;
}

                                             // void encounterEvent();
    int getTreasure() const{ return treasure;}

    void addTreasure(int amount);

    void showStats();

};

#endif // PLAYER_H