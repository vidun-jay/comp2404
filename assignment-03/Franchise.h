#ifndef FRANCHISE_H
#define FRANCHISE_H

#include "Entity.h"
#include "defs.h"

class Franchise: public Entity {
    /* Member Functions */
    public:
        /* Constructors */
        Franchise(const string& name = "Unknown", const Location& = Location());

        /* Others */
        void print() const;

        /* Class Functions */
        static void printMenu();
        static string getMenu(int index);

    /* Member Variables */
    private:
        static const char code;
        static int nextId;
        static const string menu[MENU_ITEMS];
};

#endif // FRANCHISE_H