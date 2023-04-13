#include "Criteria.h"

ostream& operator<<(ostream& os, const Criteria& criteria) {
    criteria.print(os);
    return os;
}

/****************
 * CONSTRUCTORS *
 ****************/
Cat_Criteria::Cat_Criteria(const string& category) : category(category) {}
Date_Criteria::Date_Criteria(const Date& start, const Date& end) : start(start), end(end) {}
CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category) : Date_Criteria(start, end), Cat_Criteria(category) {}

/*********
 * OTHER *
 *********/

/* Cat_Criteria Functions */
bool Cat_Criteria::matches(const Photo& photo) const {
    return photo.getCategory() == category;
}

void Cat_Criteria::print(ostream& os) const {
    os << "Matching category: " << category;
}

/* Date_Criteria Functions */
bool Date_Criteria::matches(const Photo& photo) const {
    return photo.getDate() <= this->end && !(photo.getDate() < this->start);
}

void Date_Criteria::print(ostream& os) const {
    os << "Photos taken between " << start << " and " << end << " are a match.";
}

/* CandD_Criteria Functions */
bool CandD_Criteria::matches(const Photo& photo) const {
    return (Cat_Criteria::matches(photo) && Date_Criteria::matches(photo));
}

void CandD_Criteria::print(ostream& os) const {
    Cat_Criteria::print(os);
    Date_Criteria::print(os);
}