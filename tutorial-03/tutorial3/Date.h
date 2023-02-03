#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {

	public:
		/* Constructors */
		Date(int = 1901, int = 1, int = 1);
		Date(Date&);
		~Date();

		/* Setters */
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);

		/* Getters */
		int getDay();
		int getMonth();
		int getYear();
		string getMonthName();

		/* Other Functions */
		bool equals(Date& d);
		bool lessThan(Date& d);
		void addDays(int days);
		void print();

	private:
		// functions
		int getMaxDay();

		// variables
		int day;
		int month;
		int year;

};
#endif