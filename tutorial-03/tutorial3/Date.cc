#include "Date.h"

Date::Date(int y, int m, int d) {
	setDate(y,m,d);
	cout<<endl<<"In Date ctor ..."<<year<<endl;
}

Date::Date(Date& d) {
	setDate(d.year,d.month,d.day);
	cout<<endl<<"In Date COPY ctor ..."<<year<<endl;
}

Date::~Date() {
		cout<<endl<<"In Date dtor ..."<<year<<endl;
}

// setters
void Date::setDay(int d) {
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m) {
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y) {
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(Date& d) {
	setDate(d.year, d.month, d.day);
}


// getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
string Date::getMonthName(){
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	return months[month-1];
}

void Date::print() {
	cout << getMonthName()<<" "<<day<<", "<<year<<endl;
}

int Date::getMaxDay() {
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

/**
 * Check if two dates are equal to current object
 * @param d: date to compare to current object
 * @return (bool) whether or not the two dates are equal
 */
bool Date::equals(Date& d) {
	if (year == d.year && month == d.month && day == d.day) return true;
	else return false;
}

/**
 * Finds whether date1 comes before date2
 * @param d: date to compare to current object
 * @return (bool) return true if the Date in question comes before d and false otherwise
 */
bool Date::lessThan(Date& d) {
	if (year < d.year) return true;
	if (year > d.year) return false;
	//years are equal
	if (month < d.month) return true;
	if (month > d.month) return false;
	//months are equal
	return (day < d.day);
}

/**
 * Advances current object's date by number of days in `days` parameter
 * @param days: number of days to increment
 */
void Date::addDays(int days) {
	this->day += days;
}