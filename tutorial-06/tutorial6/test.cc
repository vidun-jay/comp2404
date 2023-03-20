#include <istream>
#include <string>

#include "defs.h"
#include "Order.h"
#include "Queue.h"

#define ARR 3

using namespace std;

const string names[5] = {"Abe","Bae","Cedric","Deb","Elise"};
const int menuItems[5] = {1,2,3,3,2};
const Location locs[5];

int orderTest();
int edgeTest();

int main(){

  
    int choice = 0;
    cin >> choice;
    int ret = 0;
    switch(choice){
      case 0: ret = orderTest(); break;
      case 1: ret = edgeTest(); break;
    }

    return ret;
  
}

int orderTest(){
    Order* orders[5];
    for (int i = 0; i < 5; ++i){
        orders[i] = new Order(names[i],menuItems[i], locs[i]);
    }
    Queue* q = new Queue();

    cout<<"Adding 5 Orders to q"<<endl;
    for (int i = 0; i < 5; ++i){
        cout<<"Adding ";
        orders[i]->print();
        q->addLast(orders[i]);
    }

    Order* order;

    cout<<endl<<"Removing 5 Orders from q"<<endl;

    for (int i = 0; i < 5; ++i){
        order = q->popFirst();
        if (order != orders[i]){
            cout<<"Error, wrong order"<<endl;
            return 1;
        }
        cout<<"Removing: ";
        order->print();
    }

    cout<<"Removed successfully in order, deleting queue, then deleting orders..."<<endl;

    delete q;
    for (int i = 0; i < 5; ++i){
        delete orders[i];
    }
    return 0;
}

int edgeTest(){
  Queue* q = new Queue();
  if(q->empty()){
        cout<<"Queue is empty!"<<endl;
  }else{
        cerr<<"Error: Queue not empty!"<<endl;
        return 1;
  }
  Order* orders[5];
  cout<<"Adding orders..."<<endl;
  for (int i = 0; i < 5; ++i){
      orders[i] = new Order(names[i],menuItems[i], locs[i]);
      orders[i]->print();
      q->addLast(orders[i]);
  }
 

  Order* order;

  cout<<endl<<"Removing all but one Order ..."<<endl;
  for (int i = 0; i < 4; ++i){
      cout<<"Removing: ";
      q->popFirst()->print();
  }

  order = q->peekFirst();

  if (order != orders[4]){
      cout<<"Error, wrong Order left"<<endl;
      return 1;
  }else{
    cout<<endl;
    order->print();
    cout<<" found in front, success!"<<endl;
  }

  cout<<endl<<"Adding back 4 Orders"<<endl;
  for (int i = 0; i < 4; ++i){
      q->addLast(orders[i]);
      orders[i]->print();
  }

  order = q->peekFirst();
  if (order != orders[4]){
      cout<<"Error, wrong Order in front"<<endl;
      return 1;
  }

  cout<<endl;
  order->print();
  cout<<" found in front, success!"<<endl<<endl;

  cout<<"Removing all Orders"<<endl;
  for (int i = 0; i < 5; ++i){
      q->popFirst()->print();
  }

  cout<<endl<<"peeking at first in queue..."<<endl;
  order = q->peekFirst();

  if (order!= nullptr){
      cout<<"peekFirst should return nullptr on empty Queue"<<endl;
      return 1;
  }else{
      cout<<"nullptr returned, success!"<<endl<<endl;
  }

  cout<<"Adding back 5 Orders"<<endl;
  for (int i = 0; i < 5; ++i){
      q->addLast(orders[i]);
  }

  order = q->peekFirst();
  if (order != orders[0]){
      cout<<"Error, wrong Order in front"<<endl;
      return 1;
  }
  
  cout<<endl<<"Removing and printing everything in queue..."<<endl;

  while(!q->empty()){
    order = q->popFirst();
    order->print();
  }

  cout<<"Tests complete, deleting queue"<<endl;

  delete q;

  cout<<endl<<"Deleting orders..."<<endl;

  for (int i = 0; i < 5; ++i){
      delete orders[i];
  }

  return 0;

}


