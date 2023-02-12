#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"

class Reservation {
    public:
        /* Constructor */
        Reservation(string customer_name, Date& check_in, int duration);

        /* Deconstructor */

        /* Other Functions */
        void setDuration(int duration);
        bool overlaps(Reservation& r);
        bool lessThan(Reservation& res);
        bool lessThan(Date& d);
        void print();
    private:
        string customer_name;
        Date check_in;
        int duration;
};

#endif // ROOM_H