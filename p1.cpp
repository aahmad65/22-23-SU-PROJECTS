// Aidan Ahmad
// p1.cpp

#include <iostream>

using namespace std;

int main()
{
  string name, place, animal, petname, spouse;
  int age, age2;
  
  cout << endl << endl;

  cout << "Welcome to the word game. In this game you will enter words for "
       << "certain prompts" << endl
       << "similar to the game MadLibs" << endl;

  cout << endl << endl;
  
  cout << "Please enter a name: ";
  cin >> name;
  
  cout << "Please enter an age: ";
  cin >> age;;

  cout << "Please enter a one-word state: ";
  cin >> place;

  cout << "Please enter a one-word animal: ";
  cin >> animal;
  
  cout << "Please enter a pet name: ";
  cin >> petname;

  cout << "Please enter another name: ";
  cin >> spouse;

  cout << "Please enter another age: ";
  cin >> age2;

  cout << endl << endl;

  cout << "There was once a human named " << name << " who lived in " << place
       << ". When they were " << endl <<  age << ", they adopted a(n) "
       << animal << " named " << petname << ". " << name
       << " eventually fell in love" << endl
       << "with " << spouse << " who was " << age2 << ". They lived happily"
       << " ever after.";

  cout << endl << endl;

  cout << "Thank you for playing. Have a good day!" << endl << endl;

  return 0;
}
