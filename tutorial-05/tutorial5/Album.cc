#include "Album.h"

/****************
 * CONSTRUCTORS *
 ****************/

/**
 * @brief Create an Album object
 * @param title: Album title
 * @param description: Album description
 */
Album::Album(const string& title, const string& description) {
    this->title = title;
    this->description = description;
}

/**
 * @brief Copy an Album object
 * @param copy: new `Album` to copy to
 */
Album::Album(Album& copy) {
    // copy title and description into new Album
    this->title = copy.title;
    this->description = copy.description;

    // allocate memory for the new PhotoArray
    this->photo_array = new PhotoArray();

    // (deep) copy contents from original into new one
    for (int i = 0; i < copy.photo_array->size(); ++i) {
        Photo* original_photo = copy.photo_array->get(i);
        // ? Do I need to write a copy constructor here?
        Photo* copied_photo = new Photo(*original_photo);
        this->photo_array->add(copied_photo);
    }
}

/**
 * @brief Deconstructor
 *
 */
Album::~Album() { delete this->photo_array; }

/*******************
 * GETTERS/SETTERS *
 *******************/

/**
 * @brief Getter for `title`
 *
 */
string Album::getTitle() { return this->title; }

/**
 * @brief Getter for size of `photo_array`
 *
 */
int Album::size() { return this->photo_array->size(); }

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Checks if two Albums have the same title
 * @param title: title to check
 * @return true if `this` Album's title == `title`,
 * @return false otherwise
 */
bool Album::equals(const string& title) { return this->title == title; }

/**
 * @brief Checks if one album comes before another alphabetically
 * @param alb: album to compare with
 * @return true if `this` Album comes *before* `alb`,
 * @return false otherwise
 */
bool Album::lessThan(Album& alb) {
    int comparison = this->title.compare(alb.title);
    // this Album's title comes before `alb`
    if (comparison < 0) return true;
    // otherwise they're either equal or this Album's title comes AFTER `alb`
    else return false;
}

/**
 * @brief Add a given photo to the `PhotoArray`
 * @param photo: pointer to photo to add
 * @return true if successful,
 * @return false if array is full
 */
bool Album::add(Photo* photo) {
    // add photo to array and return success status
    return this->photo_array->add(photo);
}

/**
 * @brief Add a given photo to the `PhotoArray` at given index
 * @param index: index to add to
 * @param photo: pointer to photo to add
 * @return true if successful,
 * @return false if array is full
 */
bool Album::add(int index, Photo* photo) {
    // add photo to array at index and return success status
    return this->photo_array->add(index, photo);
}

/**
 * @brief Returns pointer to the Photo with given title
 * @param title: title of photo to search for
 * @return pointer to photo if found,
 * @return `NULL` otherwise
 */
Photo* Album::get(const string& title) {
    return this->photo_array->get(title);
}

/**
 * @brief Returns a pointer to the photo at given index
 * @param index: index of pointer to return
 * @return pointer to photo if found,
 * @return NULL otherwise
 */
Photo* Album::get(int index) {
    return this->photo_array->get(index);
}

/**
 * @brief Remove a photo from the `PhotoArray` with a given title
 * @param title: title of photo to remove
 * @return the pointer of removed photo
 * @return NULL otherwise
 */
Photo* Album::remove(const string& title) {
    // remove the photo from the array and return its pointer
    return this->photo_array->remove(title);
}

/**
 * @brief Remove a photo from the `PhotoArray` at a given index
 * @param index: index to remove
 * @return the pointer of removed photo
 * @return NULL otherwise
 */
Photo* Album::remove(int index) {
    // remove the photo from the array at given index and return its pointer
    return this->photo_array->remove(index);
}

/**
 * @brief Prints out all metadata for `this` Album
 *
 */
void Album::print() {
    cout << "Album Title: " << this->title << endl;
    cout << "Album Description: " << this->description << endl;
    cout << "Size: " << this->photo_array->size() << endl;
}

/**
 * @brief Prints out all metadata for `this` Album + displays all photos
 *
 */
void Album::display() {
    this->print();
    for (int i = 0; i < this->photo_array->size(); ++i)
        this->photo_array->get(i)->display();
}