#ifndef ORDER_H
#define ORDER_H

#include "Location.h"

class Order {
    // Member functions
    public:
        /* Constructors */
        Order(const string& name, int menu_item, const Location& location);

        /* Getters & Setters */
        // ! REVISE
        const Location getLocation() const;

        /* Other */
        void print() const;

    // Member variables
    private:
        string name;
        int menu_item;
        Location location;
};

#endif // ORDER_H