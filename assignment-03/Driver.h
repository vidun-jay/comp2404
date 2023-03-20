#ifndef DRIVER_H
#define DRIVER_H

#include "Entity.h"

class Driver: public Entity {
    /* Member Functions */
    public:
        /* Constructors */
        Driver(const string& name = "Unknown", const Location& = Location());

        /* Others */
        bool isFree() const;
        void print() const;

    /* Member Variables */
    private:
        static const char code;
        static int nextId;
};

#endif // DRIVER_H