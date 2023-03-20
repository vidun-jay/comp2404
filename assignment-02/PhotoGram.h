#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "AlbumArray.h"

class PhotoGram {
    public:
        // Constructors
        PhotoGram();
        ~PhotoGram();

        // Member Functions
        bool addAlbum(const string& title, const string& description);
        bool removeAlbum(const string& title);
        bool addPhoto(const string& title, const Photo& photo);
        bool removePhoto(const string& albumTitle, const string& photoTitle);
        Album* downloadAlbum(const string& title) const;
        Photo* downloadPhoto(const string& albumTitle, const string& photoTitle) const;
        void printAlbums() const;
        void displayAlbums() const;

    // Member Variables
    private:
        AlbumArray* album_array;
};

#endif // PHOTOGRAM_H