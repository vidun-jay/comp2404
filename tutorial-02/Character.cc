#include "Character.h"

// using namespace std;

Character::Character(const string& name, int maxHealth, int damage) {
    // initialize member variables using parameters
    this->name = name;
    this->maxHealth = maxHealth;
    this->damage = damage;
    this->currentHealth = maxHealth;
}

/**
 * Getter for name member variable
 * @return (string) name of current Character
 */
string Character::getName() {return this->name;};

/**
 * Function to subtract damage from health
 * @param damage: how much damage to remove from health
 */
void Character::takeDamage(int damage) {
    // subtract the parameter value from the currentHealth
    this->currentHealth -= damage;

    // if currentHealth drops below 0, reset it to 0
    if (this->currentHealth < 0)
        this->currentHealth = 0;
}

/**
 * Essentially a getter for the damage
 * @return (int) damage of current Character
 */
int Character::strike() {return this->damage;}

/**
 * Print the name and current health of current Character
 */
void Character::print() {
    cout << this->name << " [Health: " << this->currentHealth << "]" << endl;
}