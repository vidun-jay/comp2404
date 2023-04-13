#include <istream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Date.h"
#include "Array.h"

using namespace std;

int testAddRemove();

int main(){

    return testAddRemove();
}

int testAddRemove(){
    Array<Date*> arr;

    Date* dates[10];

    if (arr.size()!=0){
      cout<<"Error, size of empty array not 0"<<endl;
      return 1;
    }

    cout <<"Adding 10 dates"<<endl;

    for (int i = 0; i < 10; ++i){
        dates[i] = new Date(2021,9,i+1);
        arr+=dates[i];
        cout<<*dates[i]<<endl;
    }

    if (arr.size()!=10){
      cout<<"Error, size of array should be 10, instead it is "<<arr.size()<<endl;
      return 1;
    }else{
      cout<<"Size is 10, correct"<<endl;
    }

    if (arr.isFull()){
      cout<<"Error, array (should be size 30) is full. Size: "<<arr.size()<<endl;
      return 1;
    }else{
      cout<<"Array is not full, correct"<<endl;
    }

    cout<<"Remove every second date:"<<endl;
    int count = 0;
    for (int i = 0; i < 10; i+=2){
        arr-=dates[i];
    }

    if (arr.size()!=5){
      cout<<"Error, size of array should be 5, instead it is "<<arr.size()<<endl;
      return 1;
    }else{
      cout<<"Size is 5, correct"<<endl;
    }

    // for (int i = 0; i < 5; ++i){
    //     cout<<*arr[i]<<endl;
    // }

    cout << *arr[0] << endl;

    cout<<"Remove all but 2 dates:"<<endl;
    for (int i = 0; i < 7; ++i){
        arr-=dates[i];
    }

    cout<<"Printing 2 dates:"<<endl;
    stringstream s1, s2;
    for (int i = 0; i < arr.size(); ++i){
        cout<<*arr[i]<<endl;
        s1<<*arr[i]<<endl;
    }

    s2 << *dates[7] <<endl << *dates[9] <<endl;

    if (s1.str() == s2.str()){
      cout<<"Dates are correct"<<endl;
    }else{
      cout<<"Dates are not correct:"<<endl<<s1.str()<<"Should be:"<<endl<<s2.str()<<endl;
      return 1;
    }

    cout<<"Testing clear"<<endl;
    arr.clear();
    if (arr.size()!=0){
      cout<<"Error, size of array should be 0, instead it is "<<arr.size()<<endl;
      return 1;
    }else{
      cout<<"Size is 0, correct"<<endl;
    }


    cout <<"Deleting 10 dates"<<endl;

    for (int i = 0; i < 10; ++i){
        delete dates[i];
    }
    return 0;
}