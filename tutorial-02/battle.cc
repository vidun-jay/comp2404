#include "battle.h"

/**
 * Fight function for the Gondor namespace
 * @param fighter: fighter character
 * @param orc: orc character
 */
void Gondor::fight(Character& fighter, Character& orc) {
    // fighter strikes orc (advantage)
    orc.takeDamage(fighter.strike() + 1);
    // print damage message
    cout << ">" << fighter.getName() << " hits " << orc.getName() << " for " << fighter.strike() + 1 << " damage! (+1 environment bonus)" << endl;

    // orc strikes fighter (disadvantage)
    fighter.takeDamage(orc.strike() - 1);
    // print damage message
    cout << ">" << orc.getName() << " hits " << fighter.getName() << " for " << orc.strike() - 1 << " damage!" << endl;
}

/**
 * Fight function for the Mordor namespace
 * @param fighter: fighter character
 * @param orc: orc character
 */
void Mordor::fight(Character& fighter, Character& orc) {
    // fighter strikes orc (disadvantage)
    orc.takeDamage(fighter.strike() - 1);
    // print damage message
    cout << ">" << fighter.getName() << " hits " << orc.getName() << " for " << fighter.strike() - 1 << " damage!" << endl;

    // orc strikes fighter (advantage)
    fighter.takeDamage(orc.strike() + 1);
    // print damage message
    cout << ">" << orc.getName() << " hits " << fighter.getName() << " for " << orc.strike() + 1 << " damage! (+1 environment bonus)" << endl;
}