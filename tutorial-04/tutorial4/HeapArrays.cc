#include "HeapArrays.h"

/****************
 * CONSTRUCTORS *
 ****************/

HeapArrays::HeapArrays() : size(0) {}

HeapArrays::~HeapArrays() {
    delete[] photos;
    for (int i = 0; i < size; i++) delete photo_pointers[i];
    delete[] photo_pointers;
}

/*******************
 * GETTERS/SETTERS *
 *******************/

Photo* HeapArrays::getObjectArray() { return photos; }
Photo** HeapArrays::getPointerArray() { return photo_pointers; }

/********************
 * MEMBER FUNCTIONS *
 ********************/

void HeapArrays::addPhoto(Photo photo) {
    // if not enough space, return
    if (size >= ARR_SIZE) return;
    // add to photos array
    photos[size] = photo;
    // dynamically allocate a copy of Photo object
    Photo* photo_ptr = new Photo(photo);
    photo_pointers[size] = photo_ptr;
    size++; // increment size
}