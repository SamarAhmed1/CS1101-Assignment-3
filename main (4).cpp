#include "Customer.h"
#include "Mechanic.h"
#include "Queue.h"
#include <fstream>

int main() {
  ifstream in("mechanics.txt"); // opens and reads the file mechanic.txt
  if (in.fail()) {              // check if file fails to open
    cout << "failed to open the file" << endl;
    return 0;
  }
  int size;   // first it will read the number of mechanics
  in >> size; // input the size
  Mechanic *mech = new Mechanic[size]; // create an array of mechanic object
  string name, ID;
  int age;
  int M, hour, mins;
  // loop on the mechnics one by one
  for (int i = 0; i < size; i++) {
    in >> name; // input into name
    mech[i].setName(name);
    in >> age; // input into age
    mech[i].setAge(age);
    in >> ID; // input into ID
    mech[i].setID(ID);
    in >> M; // Read number of appointments
    // loop M iterations to read all appointments
    for (int j = 0; j < M; j++) {
      in >> hour; // input into hour
      in >> mins; // input into mins
      mech[i].addAppointment(hour,
                             mins); // add hour and mins into the mechanic array
    }
  }
  in.close(); // close the file
  cout << "Available Mechanic List : " << endl;
  for (int i = 0; i < size; i++) {
    mech[i].printInfo(); // print the mechanic information
  }
  cout << endl;
  in.open("customers.txt"); // open customer file
  if (in.fail()) {          // check if file fails to open
    cout << "failed to open customer file" << endl;
    return 0;
  }
  // first read number of customers
  int NCustomer;
  in >> NCustomer;                               // input number of customers
  Customer *customers = new Customer[NCustomer]; // array of customers
  for (int i = 0; i < NCustomer;
       i++) { // input in every index depending on size the name, age and ID
    in >> name;
    customers[i].setName(name);
    in >> age;
    customers[i].setAge(age);
    in >> ID;
    customers[i].setID(ID);

    in >> hour; // read data for hour and minutes in appointment
    in >> mins;
    Appointment app; // assign appointment to customer
    app.hour = hour;
    app.mins = mins;
    customers[i].setAppointment(app); // add appointments into the array of customers
  }
  in.close(); // close the file

  // bubble sorting depending on the appointment
  for (int i = 0; i < NCustomer - 1; i++) { // using the < operating overload
    for (int j = 0; j < NCustomer - 1; j++) {
      if (customers[j] > customers[j + 1]) {
        swap(customers[j], customers[j + 1]);
      }
    }
  }

  Queue<Customer> QCustomers;
  for (int i = 0; i < NCustomer; i++) {
    QCustomers.push(customers[i]); // loop on array and add it to the queue
                                   // called QCustomers
  }

  Queue<Mechanic> QMechanic;
  for (int i = 0; i < size; i++) {
    QMechanic.push(
        mech[i]); // loop on the mechanic and add it to the que called QMechanic
  }

  cout << "The Customers are: " << endl;
  while (!QCustomers.isEmpty()) { // loop on Queue
    Customer t = QCustomers.pop(); // read the first customer and remove from the queue
    for (int i = 0; i < QMechanic.length(); i++) {
      Mechanic c = QMechanic.pop(); // loop on mechanic to find the first available
      if (c.isAvailable(t.getAppointment())) { // to check if mechanic is availbale by
        // checking the appointent of customer
        t.setMechanicID(c.getID()); // if its true then send the mechanics ID to
                                    // the customers Mechanic ID
        t.printInfo();     // print the info
       QMechanic.push(c); // return the ID to the queue
        break;
      }
      QMechanic.push(c); // to not make it repeptitive
    }
  }
}