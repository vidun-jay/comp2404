#include "Reservation.h"

/* Constructor */
Reservation::Reservation(string customer_name, Date& check_in, int duration) {
    this->customer_name = customer_name;
    this->check_in.setDate(check_in);
    setDuration(duration);
}

/* Setter */
void Reservation::setDuration(int duration) { this->duration = duration; }

/* Other */

/**
 * Checks if two `Reservations` have a day in common
 * @param r: reservation to check against current object
 * @return true if they have date in common, false otherwise
 */
bool Reservation::overlaps(Reservation& r) {
    /* loop through the dates in the reservation and check
    if they're equal using the .equals() method */
    Date date1 = this->check_in;
    Date date2 = r.check_in;

    if (date1.equals(date2)) return true;

    date1.addDays(this->duration);
    date2.addDays(r.duration);

    if (r.check_in.lessThan(this->check_in) && this->check_in.lessThan(date2) ||
        this->check_in.lessThan(r.check_in) && r.check_in.lessThan(date1)) {
            return true;
    } return false;
}

/**
 * Checks whether a Reservation occurs before another
 * @param res: reservation to check against current object
 * @return (bool) true if this Reservation occurs
 *         before the res Reservation and false otherwise
 */
bool Reservation::lessThan(Reservation& res) {
    // if the Reservations overlap return false
    if (this->overlaps(res)) return false;

 /* otherwise return true if this Reservation occurs before
    the res Reservation and false otherwise */
    else {
        if (this->lessThan(res)) return true;
    } return false;
}

/**
 * Check if reservation occurs before given date
 * @param d: date to check
 * @return true if this Reservation occurs before d
 */
bool Reservation::lessThan(Date& d) {
    if (this->check_in.lessThan(d)) return true;
    else return false;
}

/**
 * Prints all Reservation data
 */
void Reservation::print() {
    // cout << "Reservation for " << this->customer_name << " on " << this->check_in.print();
    cout << "Reservation for " << this->customer_name << " on ";
}