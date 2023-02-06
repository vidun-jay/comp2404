#include "Hotel.h"

/* Constructor */
Hotel::Hotel() { this->size = 0; }

/* Deconstructor */
Hotel::~Hotel() {
    for (int i = 0; i < this->size; i++) delete this->rooms[i];
}

/**
 * Adds a `Room` to `Hotel`
 * @param roomNumber: room number of Room to add
 * @param bedType: bed type...
 * @param capacity: capacity...
 * @param fr: fridge required or not
 * @return true if operation successful; false otherwise
 */
bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr) {
    // if there is no space in the array, return false
    if (this->size >= MAX_ROOMS) return false;
    // add new Room object using the given parameters to array
    Room* room = new Room(roomNumber, bedType, capacity, fr);

    // if the given room number already exists return false
    for (int i = 0; i < this->size; i++)
        if (this->rooms[i]->getRoomNumber() == roomNumber) { // TODO: check
            cout << "line 28";
            delete room;
            return false;
        }

    // go through the list and put in right place, shifting as needed
    for (int i = this->size-1; i >= 0; i--) {
        if (this->rooms[i]->lessThan(*room)) {
            this->rooms[i+1] = room;
            this->size++;
            return true;
        } else {
            this->rooms[i+1] = this->rooms[i];
        }
    }

    // base case for if the room is the smallest
    this->size++;
    this->rooms[0] = room;
    return true; // success flag
}

/**
 * Deletes a room from the Hotel Rooms array
 * @param roomNumber: room number to delete
 * @return true if successful; false otherwise
 */
bool Hotel::deleteRoom(int roomNumber) {
    // loop through all Room objects
    for (int i = 0; i < this->size; i++) {
        // check is the current room has the given number
        if (this->rooms[i]->getRoomNumber() == roomNumber) {
            delete this->rooms[i];
            // add it in place and shift to close glap
            for (int j = i; j < this->size-1; j++) {
                rooms[j] = rooms[j+1];
            } this->size--; // decrement the count
            return true; // success flag
        }
    } return false; // no room with given room number exists
}

/**
 * Finds a room and assigns it to `room` parameter
 * @param roomNumber: room number to find
 * @param room: variable to assign room value
 * @return true if successful; false otherwise
 */
bool Hotel::getRoom(int roomNumber, Room** room) {
    // for every room in rooms
    for (Room* r : this->rooms) {
        // if room number is found, set room to the pointer of that room
        if (r->getRoomNumber() == roomNumber) {
            *room = r;
            return true; // success flag
        }
    } return false; // room not found
}

/**
 * Adds `Reservation` to `Hotel`
 * @param customer: customer name fpr Reservation
 * @param bedType: bed type for Reservation
 * @param capacity: capacity...
 * @param fr: fridge required
 * @param date: date of...
 * @param duration: duration of...
 * @return true if successfully added; false otherwise
 */
bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration) {
    for (int i = 0; i < this->size; i++) {
        if (this->rooms[i]->isMatch(bedType, capacity, fr)) {
            this->rooms[i]->addReservation(customer, date, duration);
            return true;
        }
    } return false;
}

/**
 * Call print on all the `Rooms`
 */
void Hotel::print() {
    for (int i = 0; i < this->size; i++)
        this->rooms[i]->print();
}

void Hotel::printReservations() {
    for (int i = 0; i < this->size; i++)
       this->rooms[i]->printReservations();
}