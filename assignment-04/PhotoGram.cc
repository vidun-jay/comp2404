#include "PhotoGram.h"

/****************
 * CONSTRUCTORS *
 ****************/

/**
 * @brief Create a new `PhotoGram` object
 *
 */
PhotoGram::PhotoGram() {}

/**
 * @brief Deconstructor
 *
 */
PhotoGram::~PhotoGram() {
    for (int i = 0; i < album_array.size(); ++i) {
        Album* album = album_array[i];
        album_array[i] = nullptr;
        delete album;
    }

    for (int i = 0; i < master_list.size(); ++i) {
        Photo* photo = master_list[i];
        master_list[i] = nullptr;
        delete photo;
    }
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
    if (this->album_array.isFull()) {
        cout << "Array full" << endl;
        return false;
    }

    album_array.add(media_factory.createAlbum(title, description));
    return true;
}

/**
 * @brief Add photos at index to photos album
 *
 * @param index:
 * @param photos:
 * @return true
 * @return false
 */
bool PhotoGram::addToAlbum(int index, Array<Photo*> photos) {
    if (index < 0 || index >= album_array.size()) {
        cout << "Invalid index" << endl;
        return false;
    }

    Album* album = album_array[index];

    if (album == NULL) {
        cout << "Album was not found" << endl;
        return false;
    }

    for (int i = 0; i < photos.size(); ++i) {
        album->addPhoto(photos[i]);
    } return true;
}

/**
 * @brief Delete album
 *
 * @param index: index to delete
 */
void PhotoGram::deleteAlbum(int index) {
    album_array.remove(album_array[index]);
}

/**
 * @brief Uploads photo
 *
 * @param title: title of photo
 * @return true if successful;
 * @return false otherwise
 */
bool PhotoGram::uploadPhoto(const string& title) {
    if (this->master_list.isFull()) {
        cout << "Not enough space" << endl;
        return false;
    }

    master_list.add(media_factory.uploadPhoto(title));
    return true;
}

void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& photos) {
    for (int i = 0; i < master_list.size(); ++i) {
        if (criteria.matches(*master_list[i]))
            photos.add(master_list[i]);
    }
}

/**
 * @brief Display album
 *
 */
void PhotoGram::displayAlbum(int index, View& view) const {
    if ((index < 0) || index >= album_array.size()) {
        cout << "Index out of bounds" << endl;
        return;
    }

    view.displayAlbum(*album_array[index]);
}

/**
 * @brief Print albums
 *
 */
int PhotoGram::printAlbums(View& view) const {
    view.printAlbums(album_array);
    return album_array.size();
}

/**
 * @brief Display photo
 *
 * @param index:
 * @param view:
 * @return * void
 */
void PhotoGram::displayPhoto(int index, View& view) const {
    if ((index < 0) || index >= master_list.size()) {
        cout << "Index out of bounds" << endl;
        return;
    }

    view.displayPhoto(*master_list[index]);
}

/**
 * @brief Print photos
 *
 */
int PhotoGram::printPhotos(View& view) const {
    view.printPhotos(master_list);
    return master_list.size();
}