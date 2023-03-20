#ifndef PHOTO_ARRAY_H
#define PHOTO_ARRAY_H

#define MAX_ARR 64

#include "Photo.h"

class PhotoArray {
  public:
    // Constructors
    PhotoArray();
    ~PhotoArray();

    // Getters/Setters
    int size();

    // Member Functions
    bool isFull() const;
    bool add(Photo*);
    bool add(int index, Photo* p);
    Photo* get(const string& title) const;
    Photo* get(int index) const;
    Photo* remove(const string& title);
    Photo* remove(int index);

  // Member Variables
  private:
    Photo** photos = new Photo*[MAX_ARR];
    int num_photos;
};

#endif // PHOTO_ARRAY_H