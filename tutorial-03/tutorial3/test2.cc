#include <iostream>
#include <string>

#include "Reservation.h"

using namespace std;

int  main(){

    //first take input for two dates
    int y1, m1, d1, dur1;
    int y2, m2, d2, dur2;

    bool overlaps= false;

    cin>>y1>>m1>>d1>>dur1;
    cin>>y2>>m2>>d2>>dur2;
    cin>>boolalpha>>overlaps;

    Date date1(y1,m1,d1);
    Date date2(y2,m2,d2);

    Reservation res1("someone", date1, dur1);
    Reservation res2("someone2", date2, dur2);

    bool o1 = res1.overlaps(res2);
    bool o2 = res2.overlaps(res1);

    res1.print();
    res2.print();

    if (o1!=o2){
        cout << "Error res1.overlaps(res2) != res2.overlaps(res1)"<<endl;
        return 1;
    }

    if(o1){
        cout<<endl<<"Reservations overlap"<<endl;
    }else{
        cout<<endl<<"Reservations do not overlap"<<endl;
    }

    if (o1 != overlaps){
        cout<<"Error, you have res1.overlaps(res2) ="<<boolalpha<<o1<<" and it should be "<<boolalpha<<overlaps<<endl;
        return 1;
    }

    cout<<endl<<"Successful overlap test"<<endl;

    return 0;

}