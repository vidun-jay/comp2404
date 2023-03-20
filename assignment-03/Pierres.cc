#include "Pierres.h"

/****************
 * CONSTRUCTORS *
 ****************/

/* specs say to include a constructor, don't see why we need one */
Pierres::Pierres() {}

Pierres::~Pierres() {
    for (Franchise* franchise : this->franchises) delete franchise;
    for (Driver* driver : this->drivers) delete driver;
}

/**********
 * OTHERS *
 **********/

/**
 * @brief Add a new Driver with the given parameters
 *
 * @param name: name for location
 * @param location: location reference
 */
void Pierres::addDriver(const string& name, const Location& location) {
    this->drivers.push_back(new Driver(name, location));
}

/**
 * @brief Add a new Franchise with the given parameters
 *
 * @param name: name for location
 * @param location: location reference
 */
void Pierres::addFranchise(const string& name, const Location& location) {
    this->franchises.push_back(new Franchise(name, location));
}

/**
 * @brief Make a new Order with the given cri- teria and add it to the Franchise that is closest to the given Location
 *
 * @param customerName: name of customer
 * @param menuItem: menu item
 * @param location: location
 */
void Pierres::takeOrder(const string& customerName, int menuItem, const Location& location) {
    Franchise* nearest_franchise = this->franchises[0];
    int franchise_distance = nearest_franchise->getLocation().getDistance(location);

    // check if array is empty
    if (this->franchises.empty()) {
        cout << "[ERROR] Franchises array empty!" << endl;
        return;
    // check if index is valid
    } else if (this->franchises[0]->getMenu(menuItem) == "Unknown menu item") {
        cout << "[ERROR] Menu item not found!" << endl;
        return;
    }

    // find closest franchise
    for (Franchise* franchise : this->franchises) {
        int distance = franchise->getLocation().getDistance(location);
        if (distance < franchise_distance) {
            nearest_franchise = franchise;
            franchise_distance = distance;
        }
    }

    // add order to franchise
    nearest_franchise->addOrder(new Order(customerName, menuItem, location));
}

/**
 * @brief Deliver and update Driver's location for numOrders/orders (whichever is less), then print and delete each Order. End at the last delivery's location. Output error for non-existent Driver ID.
 *
 * @param franchiseId: franchise ID
 * @param numOrders: number of orders
 */
void Pierres::driverPickup(const string& franchiseId, int numOrders) {
    bool match = false;
    Franchise* franchise;

    for (Franchise* f : this->franchises) {
        if (f->equals(franchiseId)) {
            match = true;
            franchise = f;
        }
    }

    if (!match) {
        cout << "[ERROR] Franchise not found!" << endl;
        return;
    }

    Driver* nearest_driver = this->drivers[0];
    int driver_distance = nearest_driver->getLocation().getDistance(franchise->getLocation());

    // find closest Driver
    for (Driver* driver : this->drivers) {
        int distance = driver->getLocation().getDistance(franchise->getLocation());
        if (distance < driver_distance && driver->isFree()) {
            nearest_driver = driver;
            driver_distance = distance;
        }
    }

    if (nearest_driver == this->drivers[0] && !(this->drivers[0]->isFree())) {
        cout << "[WARNING] No drivers currently available." << endl;
        return;
    }

    for (int i = 0; i < numOrders; ++i) {
        nearest_driver->addOrder(franchise->getNextOrder());
    }
}

/**
 * @brief Deliver order
 *
 * @param driverId: ID of driver
 * @param numOrders: number of orders
 */
void Pierres::driverDeliver(const string& driverId, int numOrders) {
    bool match = false;
    Driver* driver;

    for (Driver* d : this->drivers) {
        if (d->equals(driverId)) {
            match = true;
            driver = d;
        }
    }

    if (!match) {
        cout << "[ERROR] Driver not found!" << endl;
        return;
    } else if (driver->isFree()) {
        cout << "[WARNING] Nothing to deliver." << endl;
        return;
    }

    for (int i = 0; i < numOrders; ++i) {
        Order* order = driver->getNextOrder();
        driver->setLocation(order->getLocation());
        cout << "Order delivered." << endl;
        order->print();
        delete order;
    }
}

/**
 * @brief Prints franchise objects
 *
 */
void Pierres::printFranchises() const {
    for (Franchise* franchise : this->franchises)
        franchise->print();
}

/**
 * @brief Prints franchise objects
 *
 */
void Pierres::printDrivers() const {
    for (Driver* driver : this->drivers)
        driver->print();
}