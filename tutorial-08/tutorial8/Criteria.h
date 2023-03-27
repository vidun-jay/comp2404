#ifndef CRITERIA_H
#define CRITERIA_H

#include "Photo.h"

class Criteria {

    friend ostream& operator<<(ostream& os, const Criteria& criteria);

    public:
        virtual bool matches(const Photo&) const = 0;
        virtual void print(ostream& os) const = 0;
};

class Cat_Criteria : virtual public Criteria {
    public:
        Cat_Criteria(const string& category);

        virtual bool matches(const Photo& photo) const;
        virtual void print(ostream& os) const;

    private:
        string category;
};

class Date_Criteria : virtual public Criteria {
    public:
        Date_Criteria(const Date& start, const Date& end);

        virtual bool matches(const Photo& photo) const;
        virtual void print(ostream& os) const;

    private:
        Date start;
        Date end;
};

class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
    public:
        CandD_Criteria(const Date& start, const Date& end, const string& category);

        virtual bool matches(const Photo& photo) const;
        virtual void print(ostream& os) const;
};

#endif // CRITERIA_H