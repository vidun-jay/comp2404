#ifndef PIERRES_H
#define PIERRES_H

#include <vector>
#include "Driver.h"
#include "Franchise.h"

class Pierres {
    /* Member Functions */
    public:
        /* Constructors */
        Pierres();
        ~Pierres();

        /* Others */
        void addDriver(const string& name, const Location& location);
        void addFranchise(const string& name, const Location& location);
        void takeOrder(const string& customerName, int menuItem, const Location& location);
        void driverPickup(const string& franchiseId, int numOrders);
        void driverDeliver(const string& driverId, int numOrders);
        void printFranchises() const;
        void printDrivers() const;

    /* Member Variables */
    private:
        vector<Driver*> drivers;
        vector<Franchise*> franchises;
};


#endif // PIERRES_H