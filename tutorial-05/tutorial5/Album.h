#ifndef ALBUM_H
#define ALBUM_H

#include "PhotoArray.h"

class Album {

    public:
        // Constructors
        Album(const string& title, const string& description);
        Album(Album& copy);
        ~Album();

        // Getters/Setters
        string getTitle();
        int size();

        // Member Functions
        bool equals(const string& title);
        bool lessThan(Album& alb);
        bool add(Photo* photo);
        bool add(int index, Photo* photo);
        Photo* get(const string& title);
        Photo* get(int index);
        Photo* remove(const string& title);
        Photo* remove(int index);
        void print();
        void display();

    // Member Variables
    private:
        string title;
        string description;
        PhotoArray* photo_array = new PhotoArray();
};

#endif // ALBUM_H