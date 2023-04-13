#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "MediaFactory.h"
#include "View.h"

class PhotoGram {
    public:
        // Constructors
        PhotoGram();
        ~PhotoGram();

        // Member Functions
        bool addAlbum(const string& title, const string& description);
        bool addToAlbum(int index, Array<Photo*> photos);
        void getPhotos(const Criteria& criteria, Array<Photo*>& photos);
        void displayAlbum(int index, View& view) const;
        void deleteAlbum(int index);
        int printAlbums(View& view) const;
        void displayPhoto(int index, View& view) const;
        int printPhotos(View& view) const;
        bool uploadPhoto(const string& title);

    // Member Variables
    private:
        Array<Album*> album_array;
        Array<Photo*> master_list;
        MediaFactory media_factory;
};

#endif // PHOTOGRAM_H