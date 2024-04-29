
#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "player.h"

 // class Player;

class Enemy {
private:
    std::string type;
    int health;
    int damage;

public:
    Enemy(std::string enemyType, int enemyHealth, int enemyDamage)
        : type(enemyType), health(enemyHealth), damage(enemyDamage) {}




    std::string getType() const { return type; }

    int getHealth() const{
        return health;
    }
    void updateHealth(int amount){
          health += amount;
          if (health < 0) health = 0;
        }

    int getDamage() const{
        return damage;
    }



    void attackPlayer(Player& player) {
        int enemyDamage = getDamage(); // Get enemy's damage
        std::cout << "The " << getType() << " attacks you and deals " << enemyDamage << " damage!" << std::endl;
        player.updateHealth(-damage); // Player takes damage from the enemy
       }
    void combat(Player& player);

    static int getRandomNumber(int min, int max) {  // move to cpp file
        static bool initialized = false;
        if (!initialized) {
            srand((unsigned)time(NULL)); // Seed the random number generator
            initialized = true;
        }
        return min + std::rand() % (max - min + 1);
    }

    void encounterMessage() const { //insdie () Player& player
        std::cout << "You encountered a " << type << "!" << std::endl;   // move
      //  std::cout << "The " << type << " attacks you and deals " << damage << " damage!" << std::endl;
     //   player.updateHealth(-damage);

    }
};


class Goblin : public Enemy {
public:
    Goblin() : Enemy("Goblin", 100, 10) {}

};

class Zombie : public Enemy {
public:
    Zombie() : Enemy("Zombie", 150, 15) {}

};

class Spider : public Enemy {
public:
    Spider() : Enemy("Spider", 80, 8) {}

};

#endif // ENEMY_H
