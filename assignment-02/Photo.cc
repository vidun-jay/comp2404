#include "Photo.h"

/***************
 * CONSTRUCTOR *
 ***************/
// ? Do I need to use member initializer syntax?
Photo::Photo(const string& title, const Date& date, const string& content) {
    this->title = title;
    this->date = date;
    this->content = content;
}

/*************
 * FUNCTIONS *
 *************/

/**
 * Check if title parameter is equal title member variable
 * @param title: title to check
 * @return true if equal,
 * @return false otherwise
 */
bool Photo::equals(string title) { return this->title == title; }

/** Prints out the Photo metadata (not including the content) */
void Photo::print() {
    cout << "Title:" << this->title;
    cout << "Date: " << this->date.getMonthName() << " " << this->date.getDay() << " " << this->date.getYear();
}

/** Prints out the Photo metadata *and* the content */
void Photo::display() {
    this->print();
    cout << this->content;
}