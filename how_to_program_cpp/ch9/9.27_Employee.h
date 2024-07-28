// Fig. 9.27: 9.27_Employee.h
// Employee class definition with a static data member to track the number of
// Employee objects in memory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
class Employee {
    friend unsigned friendCount(); // added by me

  public:
    Employee(const std::string &, const std::string &);
    ~Employee();
    std::string getFirstName() const;
    std::string getLastName() const;
    static unsigned getCount(); // return # of objects instantiated

  private:
    std::string firstName;
    std::string lastName;
    static unsigned count; // number of objects instantiated
};
#endif
