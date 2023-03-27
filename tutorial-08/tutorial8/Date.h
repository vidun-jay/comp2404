
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {

	/* Friend Functions */
	friend ostream& operator<<(ostream& os, const Date& date);

	public:
		/* Constructors */
		Date();
		Date(int year, int month, int day);
		Date(const Date&);

		/* Getters/Setters */
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);

		/* Other */
		void incDate();
		void addDays(int);
		void print() const;
		bool operator<(const Date& date) const;
		bool operator==(const Date& date) const;
		bool operator<=(const Date& other) const;

	private:
		//functions
		int getMaxDay() const;

		//variables
		int day;
		int month;
		int year;

};
#endif // DATE_H