#ifndef CAT_CRITERIA_H
#define CAT_CRITERIA_H

#include "Criteria.h"

class Cat_Criteria : virtual public Criteria {
    public:
        /* Constructors */
        Cat_Criteria(string category) : category(category) {}

        /* Other */
        virtual bool Cat_Criteria::matches(const Photo& photo) const {
            return photo.getCategory() == category;
        }

        virtual void Cat_Criteria::print(ostream& os) const {
            os << "Matching category: " << category << endl;
        }

    private:
        string category;
};

#endif // CAT_CRITERIA_H