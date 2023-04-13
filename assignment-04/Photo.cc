#include "Photo.h"

/***************
 * CONSTRUCTOR *
 ***************/

/**
 * @brief Creates a new `Photo` object
 *
 */
Photo::Photo(const string& title, const string& category, const Date& date, const string& content) {
    this->title = title;
    this->date = date;
    this->content = content;
    this->category = category;
}

/*******************
 * GETTERS/SETTERS *
 *******************/

/**
 * @brief Gets the value of title
 */
const string& Photo::getTitle() const { return this->title; }

const string& Photo::getCategory() const { return this->category; }

const Date& Photo::getDate() const { return this->date; }

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Check if title parameter is equal to title member variable
 * @param title: title to check
 * @return true if equal,
 * @return false otherwise
 */
bool Photo::equals(const string& title) const { return this->title == title; }

/**
 * @brief Prints out the Photo metadata (not including the content)
 *
 */
void Photo::print(ostream& os) const {
    os << "Title: " << this->title << " Cateogory: " << this->getCategory() << " Date: " << this->date.getMonthName() << " " << this->date.getDay() << " " << this->date.getYear() << endl;
}

/**
 * @brief Prints out the Photo metadata *and* the content
 *
 */
void Photo::display(ostream& os) const {
    this->print(os);
    os << this->content << endl;
}

/**
 * @brief Stream insertion operator overload for Photo objects
 *
 * @param os output stream to write to
 * @param photo: photo object to write
 * @return output stream
 */
ostream& operator<<(ostream& os, const Photo& photo) {
    photo.print(os);
    return os;
}