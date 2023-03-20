#include "Franchise.h"

const char Franchise::code = 'F';
int Franchise::nextId = 0;
const string Franchise::menu[MENU_ITEMS] = {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};

/****************
 * CONSTRUCTORS *
 ****************/

Franchise::Franchise(const string& name, const Location& location):
    Entity(code, ++nextId, name, location) {}

/**********
 * OTHERS *
 **********/

/**
 * @brief Prints out all the information including Location and number of Franchise
 *
 */
void Franchise::print() const {
    cout << "Franchise ID: " << this->id << ", Franchise Name: " << this->name << ", # of Orders: " << this->getNumOrders() << ", Location: ";
    this->location.print();
    cout << endl;
}

/**
 * @brief Prints menu
 *
 */
void Franchise::printMenu() {
    cout << menu[0] << endl;
    cout << menu[1] << endl;
    cout << menu[2] << endl;
}

/**
 * @brief Return menu[index] if the index is valid, or "unknown menu item" otherwise
 *
 * @param index:
 * @return string
 */
string Franchise::getMenu(int index) {
    if (index < 0 || index >= 3) return "Unknown menu item";
    return menu[index];
}