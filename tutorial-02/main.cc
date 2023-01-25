#include "battle.h"
#include <iostream>

namespace fighter {
    string name;
    int maxHealth;
    int damage;
}

namespace orc {
    string name;
    int maxHealth;
    int damage;
}

int main() {

    // prompt the user to input the name, max health, and damage for a fighter character
    cout << "FIGHTER CREATOR" << endl;
    cout << "Enter a name for your fighter character: ";
    cin >> fighter::name;
    cout << "Enter a maximum health for your fighter character: ";
    cin >> fighter::maxHealth;
    cout << "Enter a damage for your fighter character: ";
    cin >> fighter::damage;

    Character fighter(fighter::name, fighter::maxHealth, fighter::damage);

    // prompt the user to input the name, max health, and damage for a orc character
    cout << endl << "ORC CREATOR" << endl;
    cout << "Enter a name for your orc character: ";
    cin >> orc::name;
    cout << "Enter a maximum health for your orc character: ";
    cin >> orc::maxHealth;
    cout << "Enter a damage for your orc character: ";
    cin >> orc::damage;

    Character orc(orc::name, orc::maxHealth, orc::damage);

    cout<<endl;
    // print characters
    fighter.print();
    orc.print();

    cout<<endl;
    // fight in Gondor
    Gondor::fight(fighter, orc);
    cout<<endl;
    fighter.print();
    orc.print();
    cout<<endl;

    // fight in Mordor
    Mordor::fight(fighter, orc);
    cout<<endl;
    fighter.print();
    orc.print();
}