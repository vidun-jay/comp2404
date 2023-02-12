#ifndef HEAP_ARRAYS_H
#define HEAP_ARRAYS_H

#include "Photo.h"

class HeapArrays {
    public:
        /* Constructors */
        HeapArrays();
        ~HeapArrays();

        /* Getters */
        Photo* getObjectArray();
        Photo** getPointerArray();

        /* Member Functions */
        void addPhoto(Photo photo);

    private:
        Photo* photos = new Photo[ARR_SIZE];
        Photo** photo_pointers = new Photo*[ARR_SIZE];
        int size;
};

#endif // HEAP_ARRAY_H