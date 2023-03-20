#include "Entity.h"

/****************
 * CONSTRUCTORS *
 ****************/

Entity::Entity(char letter, int number, const string& name, const Location& location):
    id(letter + to_string(number)), name(name), location(location) {}

/*********************
 * GETTERS & SETTERS *
 *********************/

void Entity::setLocation(const Location& location) { this->location = location; }
const Location& Entity::getLocation() const { return this->location; }
int Entity::getNumOrders() const { return this->orders.size(); }

/**********
 * OTHERS *
 **********/

/**
 * @brief Removes and returns the Order at the front of the Queue if one exists, or returns nullptr otherwise
 *
 * @return removed node if one exists,
 * @return nullptr otherwise
 */
Order* Entity::getNextOrder() { return this->orders.popFirst(); }

/**
 * @brief Adds the given Order* to the back of the Queue
 *
 * @param order: order to add
 */
void Entity::addOrder(Order* order) { this->orders.addLast(order); }

/**
 * @brief Prints out all the information including Location and number of Orders
 *
 */
void Entity::print() const {
    cout << "ID: " << this->id << "Name: " << this->name << "Location: ";
    this->location.print();
    cout << endl;
}

/**
 * @brief Checks if id is equals to given id
 *
 * @param id: given id
 * @return true if equal,
 * @return false otherwise
 */
bool Entity::equals(const string& id) const { return this->id == id; }