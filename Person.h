#pragma once
#include "Appointment.h"
#include <iostream>
#include <string>
using namespace std;

class Person { // The base class
private:
  string Name;
  string ID;
  int Age;

public:
  Person();

  void setName(string n);
  void setID(string n);
  void setAge(int a);

  string getName();
  string getID();
  int getAge();

  void printInfo();
};