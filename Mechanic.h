#include "Person.h"

class Mechanic : public Person { // inherited from the base class person
private:
  int counter;
  Appointment *apps;

public:
  Mechanic();

  void setCounter(int c);
  void setApps(Appointment *a);
  Appointment *getApps();
  int getCounter();
  bool isAvailable(Appointment ap);
  void addAppointment(int h, int m);
  void printInfo();
};