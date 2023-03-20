#ifndef PHOTO_H
#define PHOTO_H
#include "Date.h"

class Photo {

    // Member Functions
    public:
        // Constructors
        Photo(const string& title, const Date& date, const string& content);

        // Getters/Setters
        string getTitle();

        // Member Functions
        bool equals(const string& title);
        void print();
        void display();

    // Member Variables
    private:
        string title;
        string content;
        Date date;

#endif // PHOTO_H
};