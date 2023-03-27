#ifndef PHOTO_H
#define PHOTO_H
#include "Date.h"

class Photo {

    /* Friend Functions */
    friend ostream& operator<<(ostream& os, const Photo& photo);

    /* Member Functions */
    public:

        /* Constructors */
        Photo(const string& title, const string& category, const Date& date, const string& content);

        /* Getters/Setters */
        const string& getTitle() const;
        const string& getCategory() const;
        const Date& getDate() const;

        /* Member Functions */
        bool equals(const string& title) const;
        void print(ostream& os) const;
        void display(ostream& os) const;

    /* Other */
    private:
        string title;
        string content;
        Date date;
        string category;

};
#endif // PHOTO_H