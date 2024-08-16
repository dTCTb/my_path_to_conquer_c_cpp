// Fig. 13.16: fig13_16.cpp
// Using member function fill and stream manipulator setfill to change
// the padding character for fields larger than the printed value
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int x = 10000;

    cout << x << " printed as int right and left justified\n"
         << "and as hex with internal justification.\n"
         << "Using the default pad character (space):" << endl;

    cout << showbase << setw(10) << x << endl;

    cout << left << setw(10) << x << endl;

    cout << internal << setw(10) << hex << x << endl << endl;

    cout << "Using various padding characters:" << endl;

    cout << right;
    cout.fill('*');
    cout << setw(10) << dec << x << endl;

    cout << left << setw(10) << setfill('%') << x << endl;

    cout << internal << setw(10) << setfill('^') << hex << x << endl;
}
/* execution result
 * 10000 printed as int right and left justified
 * and as hex with internal justification.
 * Using the default pad character (space):
 *      10000
 * 10000
 * 0x    2710
 *
 * Using various padding characters:
 * *****10000
 * 10000%%%%%
 * 0x^^^^2710
 */
