#include "Mechanic.h"

Mechanic::Mechanic() : Person() { // inherits from person class
  counter = 0;
  apps = new Appointment[30]; // array of appointment
}

void Mechanic::setCounter(int c) { counter = c; }    // setter for counter
void Mechanic::setApps(Appointment *a) { apps = a; } // setter for apps object

int Mechanic::getCounter() { return counter; }    // getter for counter
Appointment *Mechanic::getApps() { return apps; } // getter for apps

bool Mechanic::isAvailable(
    Appointment ap) { // function to check if machanic is available
  for (int i = 0; i < counter; i++) {
    if (apps[i].hour == ap.hour && apps[i].mins == ap.mins) {
      return false;
    }
  }

  return true;
}

void Mechanic::addAppointment(int h, int m) {
  apps[counter].hour = h;
  apps[counter].mins = m;
  counter++;
}

void Mechanic::printInfo() { // print by inheriting from class then adding extra
                             // outputs
  Person::printInfo();
  cout << "Number of appointments = " << counter << endl;
  for (int i = 0; i < counter; i++) {
    cout << apps[i].hour << " : " << apps[i].mins << endl;
  }
  cout << endl;
}