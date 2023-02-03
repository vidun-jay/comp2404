#include <iostream>
#include <string>

#include "Room.h"

using namespace std;

int  main(){

    int roomNum = 101;
    string t, type;
    int capacity = 0, cap = 0;
    bool hasFridge = true, hf = true, matches = true;

    cin >>type>>t;
    cin >>capacity>>cap;
    cin >>boolalpha>>hasFridge>>boolalpha>>hf;
    cin >>boolalpha>>matches;

    Room t1(roomNum, type, capacity, hasFridge);

    bool out = t1.isMatch(t, cap, hf);

    t1.print();

     if (out != matches){
        cout<<"Error, you have isMatch ="<<boolalpha<<out<<" and it should be "<<boolalpha<<matches<<endl;
        return 1;
    }

    cout<<endl<<"isMatch test successful"<<endl;

    return 0;
}