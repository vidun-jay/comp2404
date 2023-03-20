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

/** @brief Returns whether or not an array is full
 *
 * @return true if full,
 * @return false otherwise
 */
bool PhotoArray::isFull() { return num_photos >= MAX_ARR; }

/**
 * @brief Adds a photo pointer `p` to the back of array
 * @param p: photo pointer to add
 * @return true if successful
 * @return false otherwise
 */
bool PhotoArray::add(Photo* p) {
    // array is full return false
    if (isFull()) return false;

    photos[num_photos++] = p; // add the photo to the back of the array
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
    // index is out of bounds
    if (index < 0 || index >= num_photos) return false;

    // shift elements to the right of the index to the right
    for (int i = num_photos - 1; i > index; --i)
        photos[i] = photos[i - 1];

    // add photo to the array at the specified index
    photos[index] = p;
    return true; // success flag
}

/**
 * @brief Returns the pointer to the Photo with given title
 * @param title: title to search for
 * @return pointer to the photo if found
 * @return `NULL` otherwise
 */
Photo* PhotoArray::get(const string& title) {
    for (int i = 0; i < num_photos; ++i)
        if (photos[i]->equals(title)) return photos[i];
    return NULL;
}

/**
 * @brief Returns the pointer to the Photo at given index
 * @param index: index to search photos array
 * @return pointer to the photo if found
 * @return NULL otherwise
 */
Photo* PhotoArray::get(int index) {
    // if given index is valid
    if (index >= 0 && index < num_photos)
        return photos[index]; // return photo pointer at that index
    else return NULL; // otherwise return NULL
}

/**
 * @brief Removes a Photo pointer from the array
 * @param title: title of Photo to remove
 * @return pointer to removed photo if found
 * @return NULL otherwise
 */
Photo* PhotoArray::remove(const string& title) {
    // iterate through photos and find the one with the given title
    for (int i = 0; i < num_photos; i++) {
        if (photos[i]->equals(title)) {
            // store the pointer to the removed photo
            Photo* removed_photo = photos[i];

            // shift the elements back to close the gap
            for (int j = i; j < num_photos - 1; j++)
                photos[j] = photos[j + 1];

            num_photos--; // update num_photos
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
    if (index >= 0 && index < num_photos) {
        // store the pointer to the removed photo
        Photo* removed_photo = photos[index];

        // shift the elements back to close the gap
        for (int i = index; i < num_photos - 1; i++)
            photos[i] = photos[i + 1];

        num_photos--; // update num_photos
        // return removed photo
        return removed_photo;
    } return NULL; // if index is not valid, return NULL
}