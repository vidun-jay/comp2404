#include <iostream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Driver.h"
#include "Franchise.h"

#define ARR 5

using namespace std;

const string names[5] = {"Abe","Bae","Cedric","Deb","Elise"};

int franchiseIdTest();
int driverIdTest();
int pickUpOrderTest();

int main(){

  
    int choice = 0;
    cin >> choice;
    switch(choice){
      case 0: return franchiseIdTest();
      case 1: return driverIdTest(); 
      case 2: return pickUpOrderTest(); 
    }

    return 1;
}

// make some franchises and check their id number
int franchiseIdTest(){
    int nums[ARR] = {4,0,1,3,2};
    string strs[ARR] = {"F5","F1","F2","F4", "F3"}; 
    Franchise* franchises[ARR];
    for (int i = 0; i < ARR; ++i){
      franchises[i] = new Franchise(names[i]);
    }

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    

    //reset stringstream
    for (int i = 0; i < ARR; ++i){
        //move std::cout to an ostringstream
        std::cout.rdbuf( strCout.rdbuf() );
        franchises[nums[i]]->print();
        //replace the old std::cout
        std::cout.rdbuf( oldCoutStreamBuf );
        //grab the output and write it to the console
        string output = strCout.str();
        std::cout << output;
        //reset the stream
        strCout.str(std::string());
        //search the output
        if (output.find(strs[i])!=std::string::npos){
          cout << strs[i]<<" found, success!"<<endl;
        }else{
          cout << strs[i]<<" not found, test failed!"<<endl;
          return 1;
        }
    }

    return 0;
}

// make some drivers and check their id number
int driverIdTest(){
    int nums[ARR] = {4,0,1,3,2};
    string strs[ARR] = {"D5","D1","D2","D4","D3"}; 
    Driver* drivers[ARR];
    for (int i = 0; i < ARR; ++i){
      drivers[i] = new Driver(names[i]);
    }

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    

    //reset stringstream
    for (int i = 0; i < ARR; ++i){
        //move std::cout to an ostringstream
        std::cout.rdbuf( strCout.rdbuf() );
        drivers[nums[i]]->print();
        //replace the old std::cout
        std::cout.rdbuf( oldCoutStreamBuf );
        //grab the output and write it to the console
        string output = strCout.str();
        std::cout << output;
        //reset the stream
        strCout.str(std::string());
        //search the output
        if (output.find(strs[i])!=std::string::npos){
          cout << strs[i]<<" found, success!"<<endl;
        }else{
          cout << strs[i]<<" not found, test failed!"<<endl;
          return 1;
        }
    }

    return 0;
}

int pickUpOrderTest(){
  Driver* d  = new Driver("Elsa", Location(3,4));
  Franchise* f = new Franchise("Bobby", Location(1,1));

  if (d->getNumOrders() != 0){
    cout<<"Driver does not have 0 orders to start, test failed!"<<endl;
    return 1;
  }

  if (f->getNumOrders() != 0){
    cout<<"Franchise does not have 0 orders to start, test failed!"<<endl;
    return 1;
  }

  cout<<endl<<"Adding 3 orders to franchise..."<<endl;
  f->addOrder(new Order("alice", 2, Location()));
  f->addOrder(new Order("bucky", 3, Location()));
  f->addOrder(new Order("charlie", 1, Location()));

  if (f->getNumOrders() != 3){
    cout<<"Franchise does not have 3 orders, has "<<
          f->getNumOrders()<<", test failed!"<<endl;
    return 1;
  }

  cout<<endl<<"Driver picking up 2 orders..."<<endl;

  d->addOrder(f->getNextOrder());
  d->addOrder(f->getNextOrder());
  
  if (d->getNumOrders() != 2){
    cout<<"Driver does not have 2 orders, has "<<
      d->getNumOrders()<<" instead, test failed!"<<endl;
    return 1;
  }

  if (f->getNumOrders() != 1){
    cout<<"Franchise does not have 1 order, has "<<
          f->getNumOrders()<<", test failed!"<<endl;
    return 1;
  }

  if (d->isFree()){
    cout<<"Driver is busy delivering, but isFree returned true, test failed"<<endl;
    return 1;
  }

  cout<<endl<<"Delivering 2 orders..."<<endl;
  delete d->getNextOrder();
  delete d->getNextOrder();

  if (d->getNumOrders() != 0){
    cout<<"Driver does not have 0 orders, has "<<
      d->getNumOrders()<<" instead, test failed!"<<endl;
    return 1;
  }

  cout<<endl<<"Driver picking up order"<<endl;

  d->addOrder(f->getNextOrder());

  if (d->getNumOrders() != 1){
    cout<<"Driver does not have 1 order, has "<<
      d->getNumOrders()<<" instead, test failed!"<<endl;
    return 1;
  }

  if (f->getNumOrders() != 0){
    cout<<"Franchise does not have 0 orders, has "<<
          f->getNumOrders()<<", test failed!"<<endl;
    return 1;
  }

  cout<<endl<<"All tests passed!"<<endl;
  // all tests passed
  return 0;
}






