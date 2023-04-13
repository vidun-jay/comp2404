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

/*******************
 * GETTERS/SETTERS *
 *******************/

/**
 * @brief Getter for `title`
 *
 */
string Album::getTitle() const { return this->title; }

/**
 * @brief Getter for size of `photo_array`
 *
 */
int Album::size() const { return this->photo_array.size(); }

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Checks if two Albums have the same title
 * @param title: title to check
 * @return true if `this` Album's title == `title`,
 * @return false otherwise
 */
bool Album::equals(const string& title) const { return this->title == title; }

/**
 * @brief Add a given photo to the `PhotoArray`
 * @param photo: pointer to photo to add
 * @return true if successful,
 * @return false if array is full
 */
void Album::addPhoto(Photo* photo) {
    // add photo to array and return success status
    return this->photo_array.add(photo);
}

/**
 * @brief Returns a pointer to the photo at given index
 * @param index: index of pointer to return
 * @return pointer to photo if found,
 * @return NULL otherwise
 */
Photo* Album::getPhoto(int index) const {
    return this->photo_array[index];
}

/**
 * @brief Prints out all metadata for `this` Album
 *
 */
void Album::print(ostream& os) const {
    os << "Album Title: " << this->title << " Album Description: " << this->description << " Size: " << this->photo_array.size() << endl;
}

/**
 * @brief Prints out all metadata for `this` Album + displays all photos
 *
 */
void Album::display(ostream& os) const {
    this->print(os);
    for (int i = 0; i < this->photo_array.size(); ++i)
        this->photo_array[i]->display(os);
}