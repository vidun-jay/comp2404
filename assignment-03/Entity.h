#ifndef ENTITY_H
#define ENTITY_H

#include "Queue.h"

class Entity {

    public:
        /* Constructors */
        Entity(char, int, const string& name, const Location& location);

        /* Getters & Setters */
        void setLocation(const Location& location);
        const Location& getLocation() const;
        int getNumOrders() const;

        /* Others */
        Order* getNextOrder();
        void addOrder(Order* order);
        virtual void print() const;
        bool equals(const string& id) const;

    /* Member Variables */
    protected:
        string id;
        string name;
        Location location;
        Queue orders;
};

#endif // ENTITY_H