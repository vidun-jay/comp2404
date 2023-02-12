#ifndef PHOTO_H
#define PHOTO_H
#include "Date.h"

class Photo {

    /* Member Functions */
    public:
        /* Constructor */
        Photo(const string& title, const Date& date, const string& content);
        // ? do I need a deconstructor

        /* Functions */
        bool equals(string title);
        void print();
        void display();

    /* Member Variables */
    private:
        string title;
        string content;
        Date date;

#endif // PHOTO_H
};