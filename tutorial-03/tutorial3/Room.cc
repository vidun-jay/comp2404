#include "Room.h"

/* Constructor */
Room::Room(int room_number, string bed_type, int capacity, bool has_fridge) {
    this->room_number = room_number;
    this->bed_type = bed_type;
    this->capacity = capacity;
    this->has_fridge = has_fridge;
}

/* Getter */
int Room::getRoomNumber() { return this->room_number; }

/* Other Functions */

/**
 * Verifies that the room has the right criteria
 * @param bt: bed type to check
 * @param cap: capacity to check
 * @param f: whether fridge is required or not
 * @return true if the room is a match; false otherwise
 */
bool Room::isMatch(string bt, int cap, bool f) {
    if (this->bed_type == bt && this->capacity >= cap) {
        if (f) {
            if (this->has_fridge) return true;
        } else return true;
    } return false;
}

/**
 * Check if `this` Room's number comes before `r`'s number
 * @param r: Room to compare to `this`
 * @return true if `this` comes before `r`; false otherwise
 */
bool Room::lessThan(Room& r) {
    if (getRoomNumber() < r.getRoomNumber()) return true;
    else false;
}

/**
 * Adds Reservation to `reservations` array
 * @param customer_name: name of customer
 * @param d: check in date
 * @param duration: duration of stay
 * @return true if successfully added; false otherwise
 */
bool Room::addReservation(string customer_name, Date& d, int duration) {
    // if the array of Reservation* is full, return false
    if (this->size == this->capacity) return false;
    else {
        Reservation* new_reservation = new Reservation(customer_name, d, duration);
        for (Reservation* reservation : this->reservations)
            // if the new reservation overlaps with an existing one, return false
            if ((*new_reservation).overlaps(*reservation)) return false;
            // otherwise, add it to the reservations array
            else this->reservations[size] = new_reservation;
        size++; // increment size of the array
    } return true;
}

/**
 * Prints out the Room metadata
 */
void Room::print() {
    // print metadata
    cout << "Room Number: " << this->room_number << endl;
    cout << "Bed Type: " << this->bed_type << endl;
    cout << "Capacity: " << this->capacity << endl;
    cout << "Has Fridge: " << (this->has_fridge) ? cout << "yes" : cout << "no" << endl;
    cout << endl;
}

/**
 * Prints out the Room metadata, then every Reservation of that Room
 */
void Room::printReservations() {
    print(); // print metadata
    // print every reservation of Room
    for (Reservation* reservation : this->reservations) cout << reservation << endl;
}