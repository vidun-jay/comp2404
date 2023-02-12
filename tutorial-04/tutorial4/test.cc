#include <istream>
#include <string>

#include "HeapArrays.h"
#include "StackArrays.h"
#include "defs.h"


bool testStackObjectArray();
bool testStackPointerArray();
bool testHeapObjectArray();
bool testHeapPointerArray();

extern const string photoContent[12];

int main(){

    int choice = 0;
    cin >> choice;
    bool flag = true;
    switch(choice){
      case 0: flag = testStackObjectArray(); break;
      case 1: flag = testStackPointerArray(); break;
      case 2: flag = testHeapObjectArray(); break;
      case 3: flag = testHeapPointerArray(); break;
    }
    
    
    if (flag){
      return 0;
    }else{
      return 1;
    }
  
}

bool testHeapObjectArray(){
  HeapArrays ha;
  string title;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      Photo photo(title, Date(), photoContent[i]);
      ha.addPhoto(photo);
  }
  Photo* photo = ha.getObjectArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    photo[i].display();
  }
  return true;
}

bool testHeapPointerArray(){
  HeapArrays ha;
  string title;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      Photo photo(title, Date(), photoContent[i]);
      ha.addPhoto(photo);
  }
  Photo** photo = ha.getPointerArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    (*photo[i]).display();
  }
  return true;
}

bool testStackObjectArray(){
  StackArrays sa;
  string title;
  for (int i = 0; i < ARR_SIZE; ++i){
      cin >> title;
      Photo photo(title, Date(), photoContent[i]);
      sa.addPhoto(photo);
  }
  Photo* photo = sa.getObjectArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    photo[i].display();
  }
  return true;
}

bool testStackPointerArray(){
  StackArrays sa;
  string title;
  for (int i = 0; i < ARR_SIZE; ++i){
      cin >> title;
      Photo photo(title, Date(), photoContent[i]);
      sa.addPhoto(photo);
  }
  Photo** photo = sa.getPointerArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    (*photo[i]).display();
  }
  return true;
}

const string photoContent[12] = {
R"(
  picture
 ▄▀▀▀▀▀───▄█▀▀▀█▄
▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██
▐▒▒▒▒▒▒▒▒███▌▀▐███
 ▌▒▓▒▒▒▒▓▒██▌▀▐██
 ▌▓▐▀▀▀▀▌▓─▀▀▀▀▀)",

R"(
  picture
┼┼┼┼┼┼┼┼▓▓▓▓┼┼┼
┼╔═▒▒▒▒▓▄░░▄▓┼┼
┼▀┼▒▒▒▓▓▒──▒▓▓┼
┼┼┼▒▌▒▐┼▓▓▓▓┼┼┼)",

R"(
  picture
─▀▀▌───────▐▀▀
─▄▀░◌░░░░░░░▀▄
▐░░◌░▄▀██▄█░░░▌
▐░░░▀████▀▄░░░▌
═▀▄▄▄▄▄▄▄▄▄▄▄▀═
)",

R"(
▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒
▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒
▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒
▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒
▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒
)",
R"(
─────────█▄██▄█
█▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█
███┼█████▐████▌█████┼███
█████████▐████▌█████████
)",
R"(
█───▄▀▀▀▀▄─▐█▌▐█▌▐██
█──▐▄▄────▌─█▌▐█─▐▌─
█──▐█▀█─▀─▌─█▌▐█─▐██
█──▐████▄▄▌─▐▌▐▌─▐▌─
███─▀████▀───██──▐██
)",
R"(
─────█─▄▀█──█▀▄─█─────
────▐▌──────────▐▌────
────█▌▀▄──▄▄──▄▀▐█────
───▐██──▀▀──▀▀──██▌───
──▄████▄──▐▌──▄████▄──
)",
R"(
─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄
█░░░█░░░░░░░░░░▄▄░██░█
█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█
█░░░▀░░░▄▄▄▄▄░░██░▀▀░█
─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀
)",
R"(
║░█░█░║░█░█░█░║░█░█░║
║░█░█░║░█░█░█░║░█░█░║
║░║░║░║░║░║░║░║░║░║░║
╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝
)",
R"(
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█
█░░║║║╠─║─║─║║║║║╠─░░█
█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█

)",
R"(
───▄██▄─────────────▄▄
──█████▄▄▄▄───────▄▀
────▀██▀▀████▄───▄▀
───▄█▀▄██▄████▄─▄█
▄▄█▀▄▄█─▀████▀██▀
)",
R"(
█▓▒▓█▀██▀█▄░░▄█▀██▀█▓▒▓█
█▓▒░▀▄▄▄▄▄█░░█▄▄▄▄▄▀░▒▓█
█▓▓▒░░░░░▒▓░░▓▒░░░░░▒▓▓█
)"};