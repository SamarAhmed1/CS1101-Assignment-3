#include "Person.h"
// base class
Person::Person() { // default constructor
  Name = "";
  Age = 0;
  ID = "";
}

void Person::setName(string n) { Name = n; } // setter for name
void Person::setID(string n) { ID = n; }     // setter for ID
void Person::setAge(int a) { Age = a; }      // setter for age

string Person::getName() { return Name; } // getter for name
string Person::getID() { return ID; }     // getter for ID
int Person::getAge() { return Age; }      // getter for Age

void Person::printInfo() { // print
  cout << "Name : " << Name << endl;
  cout << "ID   : " << ID << endl;
  cout << "Age  : " << Age << endl;
}