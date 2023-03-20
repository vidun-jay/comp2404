#include "AlbumArray.h"

/****************
 * CONSTRUCTORS *
 ****************/

/**
 * @brief Creates a new `AlbumArray` object
 *
 */
AlbumArray::AlbumArray() {
    this->num_albums = 0;
}

/**
 * @brief Deconstructor
 *
 */
AlbumArray::~AlbumArray() { delete[] this->albums; }

/*******************
 * GETTERS/SETTERS *
 *******************/

/**
 * @brief Getter for size of `AlbumArray`
 *
 */
int AlbumArray::size() const { return this->num_albums; }

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Returns whether or not the AlbumArray is full
 * @return true if full,
 * @return false otherwise
 */
bool AlbumArray::isFull() const { return this->num_albums == MAX_ARR; }

/**
 * @brief Adds an Album in order as defined by Album::lessThan(Album&)
 * @param alb: album to add
 * @return true if successful,
 * @return false otherwise
 */
bool AlbumArray::add(Album* alb) {
    // array is full return false
    if (isFull()) return false;

    // find the correct index to insert at
    int index = this->num_albums;

    // shift elements to insert
    for (int i = 0; i < this->num_albums; ++i) {
        if (alb->lessThan(*this->albums[i])) {
            index = i;
            break;
        }
    }

    for (int i = this->num_albums - 1; i >= index; --i)
        this->albums[i+1] = this->albums[i];

    this->albums[index] = alb;
    this->num_albums++;
    return true;
}

/**
 * @brief Gets the Album with a given title
 * @param title: album to search for
 * @return album with given title if found
 * @return `NULL` otherwise
 */
Album* AlbumArray::get(const string& title) const {
    for (int i = 0; i < this->num_albums; ++i)
        if (this->albums[i]->equals(title)) return this->albums[i];
    return NULL;
}

/**
 * @brief Returns the pointer to the album at given index
 * @param index: index to search albums array
 * @return pointer to the album if found
 * @return NULL otherwise
 */
Album* AlbumArray::get(int index) const {
    // if given index is valid
    if (index >= 0 && index < this->num_albums)
        return this->albums[index]; // return album pointer at that index
    else return NULL; // otherwise return NULL
}

/**
 * @brief Removes a album pointer from the array
 * @param title: title of album to remove
 * @return pointer to removed album if found
 * @return NULL otherwise
 */
Album* AlbumArray::remove(const string& title) {
    // iterate through Albums and find the one with the given title
    for (int i = 0; i < this->num_albums; ++i) {
        if (this->albums[i]->equals(title)) {
            // store the pointer to the removed album
            Album* removed_album = this->albums[i];

            // shift the elements back to close the gap
            for (int j = i; j < this->num_albums - 1; j++)
                this->albums[j] = this->albums[j + 1];

            this->num_albums--; // update num_albums
            // return removed album
            return removed_album;
        }
    } return NULL; // if no album with given title exists, return NULL
}

/**
 * @brief Removes a album at a given index from albums
 * @param index: index whose album to remove
 * @return pointer to removed album if valid index
 * @return NULL otherwise
 */
Album* AlbumArray::remove(int index) {
    // if index is valid
    if (index >= 0 && index < this->num_albums) {
        // store the pointer to the removed album
        Album* removed_album = this->albums[index];

        // shift the elements back to close the gap
        for (int i = index; i < this->num_albums - 1; ++i)
            this->albums[i] = this->albums[i + 1];

        this->num_albums--; // update num_albums
        // return removed album
        return removed_album;
    } return NULL; // if index is not valid, return NULL
}