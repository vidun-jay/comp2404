#include "PhotoGram.h"

/****************
 * CONSTRUCTORS *
 ****************/

/**
 * @brief Create a new `PhotoGram` object
 *
 */
PhotoGram::PhotoGram() { this->album_array =  new AlbumArray(); }

/**
 * @brief Deconstructor
 *
 */
PhotoGram::~PhotoGram() {
    for (int i = 0; i < this->album_array->size(); ++i)
        delete this->album_array->get(i);
    delete this->album_array;
}

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Add an Album to PhotoGram's album array
 * @param title: title of album
 * @param description: description of album
 * @return true if operation successful,
 * @return false otherwise
 */
bool PhotoGram::addAlbum(const string& title, const string& description) {
    Album* new_album = new Album(title, description);
    bool output = this->album_array->add(new_album);
    if (!output) cout << "Array full.";
    return output;
}

/**
 * @brief Removes an album from album array
 * @param title: title of album to remove
 * @return true if successful,
 * @return false otherwise (album not found)
 */
bool PhotoGram::removeAlbum(const string& title) {
    // album to remove
    Album* removed_album = this->album_array->remove(title);

    // album not found
    if (removed_album == NULL) {
        cout << "Album not found." << endl;
        return false;
    }

    delete removed_album;
    return true;
}

/**
 * @brief Adds photo to a given album
 * @param alb: album to add to
 * @param photo: photo to add
 * @return true if successful,
 * @return false otherwise
 */
bool PhotoGram::addPhoto(const string& title, const Photo& photo) {
    Album* added_album = this->album_array->get(title);
    if (added_album == NULL) {
        cout << "Album not found." << endl;
        return false;
    }

    // if added successfully, return true
    if (added_album->addPhoto(new Photo(photo))) return true;
    // otherwise return false
    cout << "Album full." << endl;
    return false;
}


/**
 * @brief Removes photo from a given album
 * @param alb: album to remove from
 * @param title: title of photo to remove
 * @return true if successful,
 * @return false otherwise
 */
bool PhotoGram::removePhoto(const string& albumTitle, const string& photoTitle) {
    // get the photo with given title
    Album* removed_album = this->album_array->get(albumTitle);

    // album not found
    if (removed_album == NULL) {
        cout << "Album not found." << endl;
        return false;
    }

    // photo not found
    Photo* photo = removed_album->removePhoto(photoTitle);

    if (photo == NULL) {
        cout << "Photo not found." << endl;
        return false;
    }

    delete photo;
    // otherwise success
    return true;
}

/**
 * @brief Returns an Album pointer if the Album exists, returns NULL otherwise
 * @param title: title to get
 * @return pointer to album if it exists,
 * @return NULL otherwise
 */
Album* PhotoGram::downloadAlbum(const string& title) const {
    Album* downloaded_album = this->album_array->get(title);

    if (downloaded_album == NULL)
        cout << "Album not found." << endl;
    return downloaded_album;
}

/**
 * @brief Returns an Photo pointer if the Album exists, returns NULL otherwise
 * @param albumTitle: title of album
 * @param photoTitle: title of photo
 * @return pointer to photo if it exists,
 * @return NULL otherwise
 */
Photo* PhotoGram::downloadPhoto(const string& albumTitle, const string& photoTitle) const {
    Album* downloaded_album = downloadAlbum(albumTitle);
    if (downloaded_album == NULL) {
        cout << "Album not found." << endl;
        return NULL;
    }

    if (downloaded_album->getPhoto(photoTitle) == NULL)
        cout << "Photo not found." << endl;

    return downloaded_album->getPhoto(photoTitle);
}

/**
 * @brief Print all Albums stored in PhotoGram
 *
 */
void PhotoGram::printAlbums() const {
    for (int i = 0; i < this->album_array->size(); ++i)
        this->album_array->get(i)->print();
}

/**
 * @brief Display all Albums stored in PhotoGram
 *
 */
void PhotoGram::displayAlbums() const {
    for (int i = 0; i < this->album_array->size(); ++i)
        this->album_array->get(i)->display();
}