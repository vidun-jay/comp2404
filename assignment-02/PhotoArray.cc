#include <iostream>
using namespace std;

#include "PhotoArray.h"

/****************
 * CONSTRUCTORS *
 ****************/

/**
 * @brief Creates a new `PhotoArray` object
 *
 */
PhotoArray::PhotoArray() {
    this->num_photos = 0;
}

/**
 * @brief Deconstructor
 *
 */
PhotoArray::~PhotoArray() {
    for (int i = 0; i < this->num_photos; ++i)
        delete this->photos[i];
    delete[] this->photos;
}

/*******************
 * GETTERS/SETTERS *
 *******************/

/**
 * @brief Getter for size of `PhotoArray`
 *
 */
int PhotoArray::size() { return this->num_photos; }

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Returns whether or not an array is full
 * @return true if full,
 * @return false otherwise
 */
bool PhotoArray::isFull() const { return this->num_photos >= MAX_ARR; }

/**
 * @brief Adds a photo pointer `p` to the back of array
 * @param p: photo pointer to add
 * @return true if successful
 * @return false otherwise
 */
bool PhotoArray::add(Photo* p) {
    // array is full return false
    if (isFull()) return false;

    this->photos[this->num_photos] = p; // add the photo to the back of the array
    this->num_photos++; // increment size
    return true; // success flag
}

/**
 * @brief Add the Photo to the array at the index indicated
 * @param index: index to add to
 * @param p: photo pointer to add
 * @return true if successful
 * @return false otherwise
 */
bool PhotoArray::add(int index, Photo* p) {

    // ? check for array is full

    // index is out of bounds or if its full
    if (index < 0 || index > this->num_photos) return false;

    // shift elements to make space
    for (int i = this->num_photos - 1; i >= index; --i)
        this->photos[i + 1] = this->photos[i];

    // add photo to the array at the specified index
    this->photos[index] = p;
    this->num_photos++;
    return true; // success flag
}

/**
 * @brief Returns the pointer to the Photo with given title
 * @param title: title to search for
 * @return pointer to the photo if found
 * @return `NULL` otherwise
 */
Photo* PhotoArray::get(const string& title) const {
    for (int i = 0; i < this->num_photos; ++i)
        if (this->photos[i]->equals(title)) return this->photos[i];
    return NULL;
}

/**
 * @brief Returns the pointer to the Photo at given index
 * @param index: index to search photos array
 * @return pointer to the photo if found
 * @return NULL otherwise
 */
Photo* PhotoArray::get(int index) const {
    // if given index is valid
    if (index >= 0 && index < this->num_photos)
        return this->photos[index]; // return photo pointer at that index
    return NULL; // otherwise return NULL
}

/**
 * @brief Removes a Photo pointer from the array
 * @param title: title of Photo to remove
 * @return pointer to removed photo if found.
 * @return NULL otherwise
 */
Photo* PhotoArray::remove(const string& title) {
    // iterate through photos and find the one with the given title
    for (int i = 0; i < this->num_photos; ++i) {
        if (this->photos[i]->equals(title)) {
            // store the pointer to the removed photo
            Photo* removed_photo = this->photos[i];

            // shift the elements back to close the gap
            for (int j = i; j < this->num_photos - 1; ++j)
                this->photos[j] = this->photos[j + 1];

            this->num_photos--; // update num_photos
            // return removed photo
            return removed_photo;
        }
    } return NULL; // if no photo with given title exists, return NULL
}

/**
 * @brief Removes a photo at a given index from photos
 * @param index: index whose photo to remove
 * @return pointer to removed photo if valid index
 * @return NULL otherwise
 */
Photo* PhotoArray::remove(int index) {
    // if index is valid
    if (index >= 0 && index < this->num_photos) {
        // store the pointer to the removed photo
        Photo* removed_photo = this->photos[index];

        // shift the elements back to close the gap
        for (int i = index; i < this->num_photos; ++i)
            this->photos[i] = this->photos[i + 1];

        this->num_photos--; // update num_photos
        // return removed photo
        return removed_photo;
    } return NULL; // if index is not valid, return NULL
}