#include "Customer.h"
// inherits from person class
Customer::Customer() : Person() { // default constructor
  mechanicID = "";
  appointment.hour = 0;
  appointment.mins = 0;
}

string Customer::getMechanicID() { return mechanicID; } // getter for mechanicID
Appointment Customer::getAppointment() {
  return appointment;
} // setter for mechanicID

void Customer::setMechanicID(string n) {
  mechanicID = n;
} // setter for mechanicID
void Customer::setAppointment(Appointment app) {
  appointment = app;
} // setter for app object

bool Customer::operator==(Customer &c) { // operator overload ==
  if (appointment.hour == c.appointment.hour &&
      appointment.mins == c.appointment.mins)
    return true;
  else
    return false;
}

bool Customer::operator>(Customer &c) { // operator overload form greater than
  if (appointment.hour > c.appointment.hour)
    return true;
  else if (appointment.hour < c.appointment.hour)
    return false;
  else {
    if (appointment.mins > c.appointment.mins)
      return true;
    else
      return false;
  }
}

bool Customer::operator<(Customer &c) { // operator overload for smaller than
  if (appointment.hour < c.appointment.hour)
    return true;
  else if (appointment.hour > c.appointment.hour)
    return false;
  else {
    if (appointment.mins < c.appointment.mins)
      return true;
    else
      return false;
  }
}

void Customer::printInfo() { // print
  Person::printInfo();
  cout << "You are appointed to the mechanic with this ID: " << mechanicID
       << " at " << appointment.hour << ":" << appointment.mins << endl
       << endl;
}