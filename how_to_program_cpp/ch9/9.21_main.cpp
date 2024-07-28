// Fig. 9.21: 9.21_main.cpp
// Demonstrating composition--an object with member objects.
#include "9.17_Date.h"
#include "9.19_Employee.h"
#include <iostream>
using namespace std;

int main() {
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Employee manager("Bob", "Blue", birth, hire);

    cout << endl;
    manager.print();

    return 0;
}
/* execution result
 * Date object constructor for date: 7/24/1949
 * Date object constructor for date: 3/12/1988
 * Employee object constructor: Bob Blue
 *
 * Blue, Bob Hired: 3/12/1988 Birthday: 7/24/1949
 * Employee object destructor: Blue, Bob
 * Date object destructor for date 3/12/1988
 * Date object destructor for date 7/24/1949
 * Date object destructor for date 3/12/1988
 * Date object destructor for date 7/24/1949
 */
