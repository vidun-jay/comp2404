#include "Photo.h"

/****************
 * CONSTRUCTORS *
 ****************/

Photo::Photo(const string& title, const Date& date, const string& content) {
    this->title = title;
    this->date = date;
    this->content = content;
}

Photo::Photo() : title("Untitled"), date(Date()), content(""){}

Photo::Photo(Photo& photo) {
    string message = "[RCMP] Copyright infringement is a serious offense and can result in legal action. Please ensure you have the rights to this picture.";
    this->title = photo.title;
    this->date = photo.date;
    this->content = message + "\n";
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
bool Photo::equals(const string& title) { return this->title == title; }

/** Prints out the Photo metadata (not including the content) */
void Photo::print() {
    cout << "Title:" << this->title << endl;
    cout << "Date: " << this->date.getMonthName() << " " << this->date.getDay() << " " << this->date.getYear() << endl;
}

/** Prints out the Photo metadata *and* the content */
void Photo::display() {
    this->print();
    cout << this->content;
}