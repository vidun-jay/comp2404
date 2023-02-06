
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {

	public:
		//constructors
		Date();
		Date(int year, int month, int day);
		Date(const Date&);

		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);

		//getters
		int getDay();
		int getMonth();
		int getYear();
		string getMonthName();

		//other
		// advance this Date by 1 day
		void incDate();
		void print();
		bool equals(Date& d);
		bool lessThan(Date& d);
		void addDays(int days);
		string toString();

	private:
		//functions
		// get the number of days in this month
		int getMaxDay();

		//variables
		int day;
		int month;
		int year;

};
#endif
