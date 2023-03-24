#include "Person.h"

class Customer : public Person { // inherited from the base class person
private:
  string mechanicID;
  Appointment appointment;

public:
  Customer();

  string getMechanicID();
  Appointment getAppointment();

  void setMechanicID(string n);
  void setAppointment(Appointment app);

  // operator overload
  bool operator==(Customer &c);
  bool operator>(Customer &c);
  bool operator<(Customer &c);

  void printInfo();
};