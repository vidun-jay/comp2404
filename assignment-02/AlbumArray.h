#ifndef ALBUM_ARRAY_H
#define ALBUM_ARRAY_H

#include "Album.h"

class AlbumArray {
    public:
        // Constructors
        AlbumArray();
        ~AlbumArray();

        // Getters/Setters
        int size() const;

        // Member Functions
        bool isFull() const;
        bool add(Album* alb);
        Album* get(const string& title) const;
        Album* get(int index) const;
        Album* remove(const string& title);
        Album* remove(int index);

    // Member Variables
    private:
        Album** albums = new Album*[MAX_ARR];
        int num_albums;
};

#endif // ALBUM_ARRAY_H