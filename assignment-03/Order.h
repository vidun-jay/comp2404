#ifndef ORDER_H
#define ORDER_H

#include "Location.h"

class Order {
    /* Member Functions */
    public:
        /* Constructors */
        Order(const string& name, int menu_item, const Location& location);

        /* Getters & Setters */
        const Location& getLocation() const;

        /* Other */
        void print() const;

    /* Member Variables */
    private:
        string name;
        int menu_item;
        Location location;
};

#endif // ORDER_H