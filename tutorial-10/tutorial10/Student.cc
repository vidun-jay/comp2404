#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"

/****************
 * CONSTRUCTORS *
 ****************/

Student::Student(string s1, string s2, float g)
    : number(s1), name(s2), gpa(g)
{
  //cout<<"-- Student ctor:  "<< name<<endl;
}

Student::Student(const Student& stu)
{
  //cout<<"-- Student copy ctor:  "<< stu.name<<endl;
  name     = stu.name;
  number   = stu.number;
  gpa      = stu.gpa;
}

/*******************
 * GETTERS/SETTERS *
 *******************/

float Student::getGpa() const { return this->gpa; }
const string& Student::getNumber() const { return this->number; }
const string& Student::getName() const { return this->name; }

/*********
 * OTHER *
 *********/

bool Student::operator==(const Student& stu) const{
    return (name == stu.name &&
            number == stu.number &&
            gpa == stu.gpa);
}


ostream& operator<<(ostream& output, const Student& stu)
{
  output<<"Student:  " << stu.number << "  " << left << setw(10) << stu.name << " "
                       << "   GPA: "
                       << fixed << setprecision(2) << setw(5) << right << stu.gpa << endl;
  return output;
}