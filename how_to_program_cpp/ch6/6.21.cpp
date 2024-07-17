// Fig. 6.21: fig06_21.cpp
// Using default arguments.
#include <iostream>
using namespace std;

unsigned boxVolume(unsigned length = 1, unsigned width = 1,
                   unsigned height = 1);

int main() {
    // no arguments--use default values for all dimensions
    cout << "The default box volume is: " << boxVolume();

    // specify length; default width and height
    cout << "\n\nThe volume of a box with length 10,\n"
            "width 1 and height 1 is: "
         << boxVolume(10);

    // specify length and width; default height
    cout << "\n\nThe volume of a box with length 10,\n"
            "width 5 and height 1 is: "
         << boxVolume(10, 5);

    // specify all arguments
    cout << "\n\nThe volume of a box with length 10,\n"
            "width 5 and height 2 is: "
         << boxVolume(10, 5, 2) << endl;

    return 0;
}

unsigned boxVolume(unsigned length, unsigned width, unsigned height) {
    return length * width * height;
}

/* execution result
 * The default box volume is: 1
 *
 * The volume of a box with length 10,
 * width 1 and height 1 is: 10
 *
 * The volume of a box with length 10,
 * width 5 and height 1 is: 50
 *
 * The volume of a box with length 10,
 * width 5 and height 2 is: 100
 */
