#include <istream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Album.h"

//network data
// const string titles[3]={"Dogs","Cats", "Ferrets"};
// const string albums[3] ={"Album1", "Album2", "Album3"};
// const string albumTitles[3] ={"Irene", "Bob", "Alice"};

// extern const string content[20]; // - at end of file

extern const  string albumTitles[5];
extern const  string descriptions[5];
extern const  string photoTitles[5][5];
extern const  string photoContent[5][5];

int albumTest();
int destructorTest();
int deepCopyTest();

int main(){


    int choice = 0;
    cin >> choice;
    switch(choice){
      case 0: return albumTest();
      case 1: return destructorTest();
      case 2: return deepCopyTest();
    }
    return 0;

}

int albumTest(){
  Album* alb = new Album(albumTitles[0],descriptions[0]);
  for (int i = 0; i < 5; ++i){
          alb->add(new Photo(photoTitles[0][i], Date(2023,2,i), photoContent[i][i]));
  }
  alb->print();
  Photo* photo = alb->get(photoTitles[0][3]);
  if (photo == NULL){
    cout<<"Photo "<<photoTitles[0][3]<<" not found"<<endl;
    return 1;
  }
  cout<<"Displaying photo:"<<endl;
  photo ->display();
  delete alb;
  return 0;
}

int destructorTest(){
  Album* pc[MAX_ARRAY];
  for (int j = 0; j < 3; ++j){
    pc[j]=new Album(albumTitles[j],descriptions[j]);
    for (int i = 0; i < 5; ++i){
      pc[j]->add(new Photo(photoTitles[j][i], Date(2023,j,i), photoContent[j][i]));
    }
  }
  cout<<"Testing for memory leaks after destroying albums"<<endl;
  for (int j = 0; j < 3; ++j){
    delete pc[j];
  }

  cout<<"Destructor test complete"<<endl;
  return 0;

}

int deepCopyTest(){
  Album* alb = new Album(albumTitles[1],descriptions[1]);
  for (int i = 0; i < 5; ++i){
          if (!alb->add(new Photo(photoTitles[1][i], Date(2023,2,i), photoContent[1][i]))){
            cout<<"Photo not added"<<endl;
          }
  }



  Album* alb2 = new Album(*alb);

  while (alb->size()>0){
    delete alb->remove(0);
  }
  delete alb;

  alb2->display();

  Photo* photo = alb2->get(photoTitles[1][3]);
  if (photo == NULL){
    cout<<"Photo "<<photoTitles[1][3]<<" not found, abort "<<endl;
    return 1;
  }
  photo ->display();
  cout<<"Deep copy test complete"<<endl;
  return 0;
}
// random titles
const string albumTitles[5] = {"Animals", "Friends", "Travel", "Family", "Selfies"};

const string descriptions[5] = {"Animals from an African safari", "Friends in low places", "My trips to Cornwall", "Friends and fellow students", "Might delete later"};

const string photoTitles[5][5] =
{"Lion", "Lion 2", "Fishbowl", "Alien", "Castle", "Love", "Anonymous", "Games","Music","Welcome","Monkey", "Stranger","Ant","Turtle","Smile","Crab","City","Apple","Pig","Dog","Helicopter","Unlock","Santa's Sleigh", "Guitar","Whale"};

const string photoContent[5][5] = {
R"(
 ▄▀▀▀▀▀───▄█▀▀▀█▄
▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██
▐▒▒▒▒▒▒▒▒███▌▀▐███
 ▌▒▓▒▒▒▒▓▒██▌▀▐██
 ▌▓▐▀▀▀▀▌▓─▀▀▀▀▀)",

R"(
┼┼┼┼┼┼┼┼▓▓▓▓┼┼┼
┼╔═▒▒▒▒▓▄░░▄▓┼┼
┼▀┼▒▒▒▓▓▒──▒▓▓┼
┼┼┼▒▌▒▐┼▓▓▓▓┼┼┼)",

R"(
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
  guy fawkes
─────█─▄▀█──█▀▄─█─────
────▐▌──────────▐▌────
────█▌▀▄──▄▄──▄▀▐█────
───▐██──▀▀──▀▀──██▌───
──▄████▄──▐▌──▄████▄──
)",
R"(
  nintendo
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
)",
R"(
──▄──▄────▄▀
───▀▄─█─▄▀▄▄▄
▄██▄████▄██▄▀█▄
─▀▀─█▀█▀▄▀███▀
──▄▄▀─█──▀▄▄
)",
R"(
─▄▀▀▀▄────▄▀█▀▀█▄
▄▀─▀─▀▄▄▀█▄▀─▄▀─▄▀▄
█▄▀█───█─█▄▄▀─▄▀─▄▀▄
──█▄▄▀▀█▄─▀▀▀▀▀▀▀─▄█
─────▄████▀▀▀▀████─▀▄
)",
R"(
╔══╗░░░░╔╦╗░░╔═════╗
║╚═╬════╬╣╠═╗║░▀░▀░║
╠═╗║╔╗╔╗║║║╩╣║╚═══╝║
╚══╩╝╚╝╚╩╩╩═╝╚═════╝
)",
R"(
░░▄█▀▀▀░░░░░░░░▀▀▀█▄
▄███▄▄░░▀▄██▄▀░░▄▄███▄
▀██▄▄▄▄████████▄▄▄▄██▀
░░▄▄▄▄██████████▄▄▄▄
░▐▐▀▐▀░▀██████▀░▀▌▀▌▌
)",
R"(
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▄▄▄▒▒▒█▒▒▒▒▄▒▒▒▒▒▒▒▒
▒█▀█▀█▒█▀█▒▒█▀█▒▄███▄▒
░█▀█▀█░█▀██░█▀█░█▄█▄█░
░█▀█▀█░█▀████▀█░█▄█▄█░
████████▀█████████████
)",
R"(
┊┊┊┊┊┊┊╱▏┊┊┊┊┊┊┊
┊┊┊┊┊┊▕╱┊┊┊┊┊┊┊┊
┊┊┊╱▔▔╲┊╱▔▔╲┊┊┊┊
┊┊▕┈┈┈┈▔┈┈┈╱┊┊┊┊
┊┊▕┈┈┈┈┈┈┈┈╲┊┊┊┊
┊┊┊╲┈┈┈┈┈┈┈╱┊┊┊┊
┊┊┊┊╲▂▂▂▂▂╱┊┊┊┊┊
)",
R"(
  Piggy
▂╱▔▔╲╱▔▔▔▔╲╱▔▔╲▂
╲┈▔╲┊╭╮┈┈╭╮┊╱▔┈╱
┊▔╲╱▏┈╱▔▔╲┈▕╲╱▔┊
┊┊┊┃┈┈▏┃┃▕┈┈┃┊┊┊
┊┊┊▏╲┈╲▂▂╱┈╱▕┊┊┊
)",
R"(
╥━━━━━━━━╭━━╮━━┳
╢╭╮╭━━━━━┫┃▋▋━▅┣
╢┃╰┫┈┈┈┈┈┃┃┈┈╰┫┣
╢╰━┫┈┈┈┈┈╰╯╰┳━╯┣
╢┊┊┃┏┳┳━━┓┏┳┫┊┊┣
╨━━┗┛┗┛━━┗┛┗┛━━┻
)",
R"(
▀▀▀▀█▀▀▀▀
─▄▀█▀▀█──────▄
█▄▄█▄▄██████▀
▀▀█▀▀▀█▀▀
─▀▀▀▀▀▀▀
)",
R"(
──▄▀▀▀▄───────────────
──█───█───────────────
─███████─────────▄▀▀▄─
░██─▀─██░░█▀█▀▀▀▀█░░█░
░███▄███░░▀░▀░░░░░▀▀░░
)",
R"(
░╔╔╩╩╝
▄██▄
░░██████▄░░░░░░▄▄▄▄▄▄█
░░█▀█▀█▀█░░▄░▄████████
░▄▌▄▌▄▌▄▌░▀▄▄▄▄█▄▄▄▄█▄
)",
R"(
░▄▀▀▀▀▄░░▄▄
█░░░░░░▀▀░░█░░░░░░▄░▄
█░║░░░░██░████████████
█░░░░░░▄▄░░█░░░░░░▀░▀
░▀▄▄▄▄▀░░▀▀
)",
R"(
─────▀▄▀─────▄─────▄
──▄███████▄──▀██▄██▀
▄█████▀█████▄──▄█
███████▀████████▀
─▄▄▄▄▄▄███████▀
)"
};
