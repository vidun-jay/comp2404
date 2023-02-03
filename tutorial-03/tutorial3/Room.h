#ifndef ROOM_H
#define ROOM_H

#include "defs.h"
#include "Reservation.h"

class Room {
    public:
        /* Constructor */
        Room(int room_number, string bed_type, int capacity, bool has_fridge);

        /* Destructor */

        /* Other Functions */
        int getRoomNumber();
        bool isMatch(string bt, int cap, bool f);
        bool lessThan(Room& r);
        bool addReservation(string customer_name, Date& d, int duration);
        void printReservations();
        void print();
    private:
        int room_number;
        string bed_type;
        int capacity;
        bool has_fridge;
        Reservation* reservations[MAX_RES];
        int size;
};

#endif // ROOM_H