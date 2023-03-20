#include "Client.h"

/****************
 * CONSTRUCTORS *
 ****************/

/**
 * @brief Create a new `Client` object
 *
 */
Client::Client() { this->album_array =  new AlbumArray(); }

/**
 * @brief Deconstructor
 *
 */
Client::~Client() {
    for (int i = 0; i < this->album_array->size(); ++i)
        delete this->album_array->get(i);
    delete this->album_array;
}

/**
 * @brief Attempt to download an Album from PhotoGram with the given title
 * @param pg: PhotoGram to download from
 * @param albumTitle: title of album to download
 * @return true if successful,
 * @return false otherwise
 */
bool Client::downloadAlbum(PhotoGram* pg, const string& albumTitle) {
    Album* downloaded_album = pg->downloadAlbum(albumTitle);

    // album not found
    if (downloaded_album == NULL) return false;

    // album is full
    if (this->album_array->isFull()) {
        cout << "Album full." << endl;
        return false;
    }

    // otherwise success
    album_array->add(new Album(*downloaded_album));
    return true;
}

/**
 * @brief
 * @param pg:
 * @param albumTitle:
 * @param photoTitle:
 * @return true
 * @return false
 */
bool Client::displayOnlinePhoto(PhotoGram* pg, const string& albumTitle, const string& photoTitle) const {
    Album* display_album = pg->downloadAlbum(albumTitle);

    // album not found
    if (display_album == NULL) return false;

    // photo not found
    Photo* photo = display_album->getPhoto(photoTitle);
    if (photo == NULL) {
        cout << "Photo not found." << endl;
        return false;
    }

    // otherwise sucess
    photo->display();
    return true;
}

/**
 * @brief If the Client contains an Album with the title given,
 * and this Album has a Photo with the title given, then display this Photo
 * @param albumTitle: title of album to display
 * @param photoTitle: title of photo
 * @return true if successful,
 * @return false otherwise
 */
bool Client::displayLocalPhoto(const string& albumTitle, const string& photoTitle) const {
    Album* display_album = this->album_array->get(albumTitle);

    // album not found
    if (display_album == NULL) {
        cout << "Album not found." << endl;
        return false;
    }

    // photo not found
    Photo* photo = display_album->getPhoto(photoTitle);
    if (photo == NULL) {
        cout << "Photo not found." << endl;
        return false;
    }

    // otherwise success
    photo->display();
    return true;
}

/**
 * @brief Print every Album stored in the Client
 *
 */
void Client::printLocalAlbums() const {
    for (int i = 0; i < this->album_array->size(); ++i)
        this->album_array->get(i)->print();
}

/**
 * @brief Display every Album stored in the Client
 *
 */
void Client::displayLocalAlbums() const {
    for (int i = 0; i < this->album_array->size(); ++i)
        this->album_array->get(i)->display();
}