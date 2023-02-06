#include "Date.h"

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
	setDate(y,m,d);
}

Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d){
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
string Date::getMonthName(){
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}

//other
void Date::incDate(){
	day += 1;
	// is it now the 32nd of January (for example)? If so make it February 1st
	if (day > getMaxDay()){
		day = 1;
		month += 1;
	}

	// is it now the 13th month? (Smarch 1st) If so make it January of next year
	// https://simpsonswiki.com/wiki/Smarch
	if (month > 12){
		month = 1;
		year += 1;
	}
}

void Date::print(){
	cout << getMonthName()<<" "<<day<<", "<<year;
}


int Date::getMaxDay(){
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
	return (year == d.year && month == d.month && day == d.day);
}

/**
 * Finds whether date1 comes before date2
 * @param d: date to compare to current object
 * @return (bool) return true if the Date in question comes before d and false otherwise
 */
bool Date::lessThan(Date& d) {
	if (year < d.year) return true;
	if (year > d.year) return false;

	if (month < d.month) return true;
	if (month > d.month) return false;

	return (day < d.day);
}

/**
 * Advances current object's date by number of days in `days` parameter
 * @param days: number of days to increment
 */
void Date::addDays(int days) {
	for (int i = 0; i < days; i++) this->incDate();
}