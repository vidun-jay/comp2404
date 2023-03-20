#include "Order.h"

/****************
 * CONSTRUCTORS *
 ****************/

Order::Order(const string& name, int menu_item, const Location& location)
    : name(name), menu_item(menu_item), location(location) {}

/*********************
 * GETTERS & SETTERS *
 *********************/

Location* Order::getLocation() const { return this->getLocation(); }

/*********
 * OTHER *
 *********/

// TODO: Finish
void Order::print() const {
    cout << name << endl;
}