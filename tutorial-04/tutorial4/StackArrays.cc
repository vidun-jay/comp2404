#include "StackArrays.h"

/****************
 * CONSTRUCTORS *
 ****************/

StackArrays::StackArrays() : size(0) {}

StackArrays::~StackArrays() {
    for (int i = 0; i < size; i++) delete photo_pointers[i];
}

/*******************
 * GETTERS/SETTERS *
 *******************/

Photo* StackArrays::getObjectArray() { return photos; }
Photo** StackArrays::getPointerArray() { return photo_pointers; }

/********************
 * MEMBER FUNCTIONS *
 ********************/

void StackArrays::addPhoto(Photo photo) {
    // if not enough space, return
    if (size >= ARR_SIZE) return;
    // add to photos array
    photos[size] = photo;
    // dynamically allocate a copy of Photo object
    Photo* photo_ptr = new Photo(photo);
    photo_pointers[size] = photo_ptr;
    size++; // increment size
}