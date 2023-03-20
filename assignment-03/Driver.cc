#include "Driver.h"

const char Driver::code = 'D';
int Driver::nextId = 0;

/****************
 * CONSTRUCTORS *
 ****************/

Driver::Driver(const string& name, const Location& location):
    Entity(this->code, ++this->nextId, name, location) {}

/**********
 * OTHERS *
 **********/

/**
 * @brief Return true if the Driver currently has no Orders in their Queue, and false if they have one or more Orders in their Queue
 *
 * @return true if orders is empty,
 * @return false otherwise
 */
bool Driver::isFree() const { return this->orders.empty(); }

/**
 * @brief Prints out all the information including Location and number of Drivers
 *
 */
void Driver::print() const {
    cout << "Driver ID: " << this->id << ", Driver Name: " << this->name << ", # of Orders: " << this->getNumOrders() << ", Location: ";
    this->location.print();
    cout << endl;
}