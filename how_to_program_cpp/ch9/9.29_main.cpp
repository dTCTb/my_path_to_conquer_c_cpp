// Fig. 9.29: 9.29_main.cpp
// static data member tracking the number of objects of a class.
#include "9.27_Employee.h"
#include <iostream>
using namespace std;
extern unsigned friendCount(); // added by me

int main() {
    cout << "Number of employee before instantiation of any objects is "
         << Employee::getCount() << endl;
    {
        Employee e1("Susan", "Baker");
        Employee e2("Robert", "Jones");

        cout << "Number of employees after objects are instantiated is "
             // modified by me to demonstrate different way to get # of objects
             << ((e1.getCount() == Employee::getCount() == friendCount())
                     ? e1.getCount()
                     : -1);

        cout << "\n\nEmployee 1: " << e1.getFirstName() << ' '
             << e1.getLastName() << "\nEmployee 2: " << e2.getFirstName() << ' '
             << e2.getLastName() << "\n\n";
    }

    cout << "\nNumber of employees after objects are deleted is "
         << Employee::getCount() << endl;
    return 0;
}
/* execution result
 * Number of employee before instantiation of any objects is 0
 * Employee constructor for Susan Baker called.
 * Employee constructor for Robert Jones called.
 * Number of employees after objects are instantiated is 2
 *
 * Employee 1: Susan Baker
 * Employee 2: Robert Jones
 *
 * ~Employee() called for Robert Jones
 * ~Employee() called for Susan Baker
 *
 * Number of employees after objects are deleted is 0
 */
