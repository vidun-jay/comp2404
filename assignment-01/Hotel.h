#include "Room.h"
using namespace std;

class Hotel {
    public:
        Hotel();
        ~Hotel();
        bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
        bool deleteRoom(int roomNumber);
        bool getRoom(int roomNumber, Room** room);
        bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
        void print();
        void printReservations();
    private:
        Room* rooms[MAX_ROOMS];
        int size;
};