#ifndef ALBUM_H
#define ALBUM_H

#include "Array.h"
#include "Photo.h"

class Album {

    friend ostream& operator<<(ostream& os, const Album& album) {
        album.print(os);
        return os;
    }

    public:
        // Constructors
        Album(const string& title, const string& description);

        // Getters/Setters
        string getTitle() const;
        int size() const;

        // Member Functions
        bool equals(const string& title) const;
        void addPhoto(Photo*);
        Photo* getPhoto(int index) const;
        void print(ostream& os) const;
        void display(ostream& os) const;

    // Member Variables
    private:
        string title;
        string description;
        Array<Photo*> photo_array;
};

#endif // ALBUM_H