#ifndef CAND_CRITERIA_H
#define CAND_CRITERIA_H

#include "Date_Criteria.h"
#include "Cat_Criteria.h"

class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
    public:
        /* Constructors */
        CandD_Criteria(const Date& start, const Date& end, const string& category) : Date_Criteria(start, end), Cat_Criteria(category) {}

        /* Other */
        bool matches(const Photo& photo) const override {
            if ((Cat_Criteria::matches(photo)) && Date_Criteria::matches(photo))
                return true;
            else return false;
        }

        void CandD_Criteria::print(ostream& os) const {
            Cat_Criteria::print(os);
            Date_Criteria::print(os);
        }
};

#endif // CAND_CRITERIA_H