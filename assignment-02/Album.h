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
        string getTitle() const;
        int size() const;

        // Member Functions
        bool equals(const string& title) const;
        bool lessThan(const Album& alb) const;
        bool addPhoto(Photo* photo);
        bool addPhoto(int index, Photo* photo);
        Photo* getPhoto(const string& title) const;
        Photo* getPhoto(int index) const;
        Photo* removePhoto(const string& title);
        Photo* removePhoto(int index);
        void print() const;
        void display() const;

    // Member Variables
    private:
        string title;
        string description;
        PhotoArray* photo_array = new PhotoArray();
};

#endif // ALBUM_H