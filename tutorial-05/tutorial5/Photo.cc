#include "Photo.h"

/***************
 * CONSTRUCTOR *
 ***************/

/**
 * @brief Creates a new `Photo` object
 *
 */
Photo::Photo(const string& title, const Date& date, const string& content) {
    this->title = title;
    this->date = date;
    this->content = content;
}

/*******************
 * GETTERS/SETTERS *
 *******************/

/**
 * @brief Gets the value of title
 */
string Photo::getTitle() { return this->title; }

/********************
 * MEMBER FUNCTIONS *
 ********************/

/**
 * @brief Check if title parameter is equal to title member variable
 * @param title: title to check
 * @return true if equal,
 * @return false otherwise
 */
bool Photo::equals(const string& title) { return this->title == title; }

/**
 * @brief Prints out the Photo metadata (not including the content)
 *
 */
void Photo::print() {
    cout << "Title:" << this->title << endl;
    cout << "Date: " << this->date.getMonthName() << " " << this->date.getDay() << " " << this->date.getYear();
}

/**
 * @brief Prints out the Photo metadata *and* the content
 *
 */
void Photo::display() {
    this->print();
    cout << this->content;
}