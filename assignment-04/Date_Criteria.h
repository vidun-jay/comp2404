#ifndef DATE_CRITERIA_H
#define DATE_CRITERIA_H

#include "Criteria.h"

class Date_Criteria : virtual public Criteria {
    public:
        /* Constructors */
        Date_Criteria(Date start, Date end) : start(start), end(end) {}

        /* Other */
        virtual bool Date_Criteria::matches(const Photo& photo) const {
            if (!(photo.getDate() < this->start) && photo.getDate() <= this->end)
                return true;
            else return false;
        }

        virtual void Date_Criteria::print(ostream& os) const {
            os << "Photos taken between " << start << " and " << end << " are a match." << endl;
        }

    private:
        Date start;
        Date end;
};

#endif // DATE_CRITERIA_H