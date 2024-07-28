// clang-format off
// Fig. 9.13: Date.h
// Data class declaration
class Date {
  public:
    explicit Date(int = 1, int = 1, int = 2000);
    void print() const;

  private:
    unsigned month;
    unsigned day;
    unsigned year;
};

// Fig. 9.14: Date.cpp
// Date class member functions definitions
#include <iostream>
using namespace std;

Date::Date(int m, int d, int y)
    : month(m), day(d), year(y) {}

void Date::print() const { 
    cout << month << '/' << day << '/' << year;
}

// Fig. 9.15: fig09_15.cpp
// Demonstrating that class objects can be assigned to each other using default
// memberwise assignment
int main() {
    Date date1(7, 4, 2004);
    Date date2; // defaults to 1/1/2000
    
    cout <<   "date1 = "; date1.print();
    cout << "\ndate2 = "; date2.print();

    date2 = date1; // default memberwise assignment
    
    cout << "\n\nAfter default memberwise assignment, date 2 = ";
    date2.print(); cout.put('\n');
}
/* execution result
* date1 = 7/4/2004
* date2 = 1/1/2000
* 
* After default memberwise assignment, date 2 = 7/4/2004
*/
