#include <istream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Photo.h"
#include "Criteria.h"


using namespace std;

int testD_Criteria();
int testC_Criteria();
int testCD_Criteria();
int testPolyPrint();

bool match(Criteria*, Photo&, bool);

int main(){

    int choice = 0;
    cin >> choice;
    switch(choice){
      case 0: return testD_Criteria();
      case 1: return testC_Criteria();
      case 2: return testCD_Criteria();
      case 3: return testPolyPrint();
    }

    cout<<"Bad input: "<<choice<<endl;
    return 1;

}

bool match(Criteria* crit, Photo& photo, bool matches){
    cout<<*crit<<photo<<endl;
    cout <<"Should "<<(matches?"match":"not match")<<endl;
    bool out = crit->matches(photo);
    cout << (out?"Matched":"Did not match")<<endl;
    if (out==matches){
        cout<<"Test passed"<<endl<<endl;
        return true;
    }else{
        cout<< " *****ERROR***** "<<endl;
        return false;
    }
}

int testD_Criteria(){
    int ret = 0;
    Criteria* crit1 = new Date_Criteria(Date(2023,4,1), Date(2023,4,2));
    Criteria* crit2 = new Date_Criteria(Date(2023,4,2), Date(2023,4,3));

    //April fool's day
    Photo photo("Bear", "Animal", Date(2023, 4, 1), "grrr");

    //if both tests pass, return 0 which means no errors occured
    if (match(crit1, photo, true)&&match(crit2, photo, false)) {
        cout<<"Testing date criteria passed"<<endl<<endl;
    }else{
        cout<<"Testing date criteria DID NOT pass"<<endl<<endl;
        ret = 1;
    }
    delete crit1, crit2;

    return ret;

}

int testC_Criteria(){
    int ret = 0;
    Criteria* crit1 = new Cat_Criteria("Animal");
    Criteria* crit2 = new Cat_Criteria("People");
    Photo photo("Bear", "Animal", Date(2023, 4, 1), "grrr");

    //if both tests pass, return 0 which means no errors occured
    if (match(crit1, photo, true)&&match(crit2, photo , false))  {
        cout<<"Testing category criteria passed"<<endl<<endl;
    }else{
        cout<<"Testing category criteria DID NOT pass"<<endl<<endl;
        ret = 1;
    }
    delete crit1, crit2;
    return ret;
}

int testCD_Criteria(){

    Criteria* crit1 = new CandD_Criteria(Date(2023,4,1), Date(2023,4,2), "Animal");
    Criteria* crit2 = new CandD_Criteria(Date(2023,4,2), Date(2023,4,3), "Animal");
    Criteria* crit3 = new CandD_Criteria(Date(2023,4,1), Date(2023,4,2), "People");
    Criteria* crit4 = new CandD_Criteria(Date(2023,4,2), Date(2023,4,3), "People");

    //April fool's day
    Photo photo("Bear", "Animal", Date(2023, 4, 1), "grrr");
    //check each test for error individually
    bool pass;
    pass = match(crit1, photo, true);
    pass = match(crit2, photo, false)&&pass;
    pass = match(crit3, photo, false)&&pass;
    pass = match(crit4, photo, false)&&pass;

    delete crit1, crit2, crit3, crit4;
    if (!pass){
        cout<<"Testing artist or category criteria DID NOT pass"<<endl<<endl;
        //returning 1 indicates an error stat
        return 1;
    }

    cout<<"Testing artist or category criteria passed"<<endl<<endl;
    return 0;

}

int testPolyPrint(){
    Date date1(2023,4,1);
    Date date2(2023,5,2);
    Criteria* crit1 = new Date_Criteria(date1, date2);
    Criteria* crit2 = new Cat_Criteria("Animal");
    Criteria* crit3 = new CandD_Criteria(date1, date2, "People");


    stringstream d1, d2, ss;
    d1<<date1;
    d2<<date2;
    ss<<*crit1;
    cout<<*crit1<<endl;
    if (ss.str().find(d1.str())==string::npos){
        cout<<"Could not find "<<date1<< " in Date_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    if (ss.str().find(d2.str())==string::npos){
        cout<<"Could not find "<<date2<< " in Date_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    cout<<date1<<", "<<date2<<" found in output, test passed"<<endl<<endl;

    //reset the string stream
    ss.str(string());

    ss<<*crit2;
    cout<<*crit2<<endl;

    if (ss.str().find("Animal")==string::npos){
        cout<<"Could not find Animal in Cat_Criteria output"<<endl<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    cout<<"'Animal' found in output, test passed"<<endl<<endl;

    ss.str(string());

    ss<<*crit3;
    cout<<*crit3<<endl<<endl;

    if (ss.str().find("People")==string::npos){
        cout<<"Could not find 'People' in CandD_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    if (ss.str().find(d1.str())==string::npos){
        cout<<"Could not find "<<date1<<" in CandD_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    if (ss.str().find(d2.str())==string::npos){
        cout<<"Could not find "<<date2<<" in CandD_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    cout<<date1<<", "<<date2<<" and 'People' found in output, test passed"<<endl<<endl;
    delete crit1, crit2, crit3;
    return 0;
}