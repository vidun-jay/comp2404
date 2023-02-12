#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

using namespace std;

class Character {
    public:
        Character(const string& name, int maxHealth, int damage);
        string getName();
        void takeDamage(int damage);
        int strike();
        void print();
    private:
        string name;
        int maxHealth;
        int currentHealth;
        int damage;
};

#endif // CHARACTER_H