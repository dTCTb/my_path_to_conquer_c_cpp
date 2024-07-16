// Fig. 6.19: fig06_19.cpp
// inline function that calculates the volume of a cube.
#include <iostream>
using namespace std;

/* Definition of inline function cube. Definition of function appears
 * before function is called, so a function prototype is not required.
 * First line of function definition acts as the prototype.
 */
inline double cube(const double side) { return side * side * side; }

int main() {
    double sideValue; // stores value entered by user
    cout << "Enter the side length of your cube: ";
    cin >> sideValue;

    // calculate cube of sideValue and display result
    cout << "Volume of cube with side " << sideValue << " is "
         << cube(sideValue) << endl;
    return 0;
}
/* execution result
 * Enter the side length of your cube: 3.5
 * Volume of cube with side 3.5 is 42.875
 */
