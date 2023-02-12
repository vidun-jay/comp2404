#ifndef STACK_ARRAYS_H
#define STACK_ARRAYS_H

#include "Photo.h"

class StackArrays {
    public:
        /* Constructors */
        StackArrays();
        ~StackArrays();

        /* Getters */
        Photo* getObjectArray();
        Photo** getPointerArray();

        /* Member Functions */
        void addPhoto(Photo photo);

    private:
        Photo photos[ARR_SIZE];
        Photo* photo_pointers[ARR_SIZE];
        int size;
};

#endif // STACK_ARRAY_H