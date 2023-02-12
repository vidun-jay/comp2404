#ifndef PHOTO_H
#define PHOTO_H
#include "defs.h"
#include "Date.h"

class Photo {

    /* Member Functions */
    public:
        /* Constructors */
        Photo();
        Photo(Photo& photo);
        Photo(const string& title, const Date& date, const string& content);

        /* Functions */
        bool equals(const string& title);
        void print();
        void display();

    /* Member Variables */
    private:
        string title;
        string content;
        Date date;
};
#endif // PHOTO_H