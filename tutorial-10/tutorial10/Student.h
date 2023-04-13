#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <ostream>

using namespace std;

class TestClass;

class Student
{
  friend class TestClass;
  friend ostream& operator<<(ostream&, const Student&);
  public:
    /* Constructors */
    Student(string="000000000", string="Hey you!",  float=0.0f);
    Student(const Student&);

    /* Getters/Setters */
    float getGpa() const;
    const string& getNumber() const;
    const string& getName() const;

    /* Other */
    bool operator==(const Student&) const;


  private:
    string  number;
    string  name;
    float   gpa;
};

#endif
