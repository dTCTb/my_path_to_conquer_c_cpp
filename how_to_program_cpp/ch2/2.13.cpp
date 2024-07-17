// Fig. 2.13: fig02_13.cpp
// Comparing integers using if statements, relational operators
// and equality operators.
#include <iostream> // allows program to perform input and output

using std::cin;  // program uses cin
using std::cout; // program uses cout
using std::endl; // program uses endl

// function main begins program execution
int main() {
    int number1 = 0; // first integer to compare (initialized to 0)
    int number2 = 0; // second integer to compare (initialized to 0)

    cout << "Enter two integers to compare: "; // prompt user for data
    cin >> number1 >> number2;                 // read two integers from user

    if (number1 == number2)
        cout << number1 << " == " << number2 << endl;
    if (number1 != number2)
        cout << number1 << " != " << number2 << endl;
    if (number1 < number2)
        cout << number1 << " < " << number2 << endl;
    if (number1 > number2)
        cout << number1 << " > " << number2 << endl;
    if (number1 <= number2)
        cout << number1 << " <= " << number2 << endl;
    if (number1 >= number2)
        cout << number1 << " >= " << number2 << endl;
} // end function main
/* execution result
 * Enter two integers to compare: 3 7
 * 3 != 7
 * 3 < 7
 * 3 <= 7
 * Enter two integers to compare: 22 12
 * 22 != 12
 * 22 > 12
 * 22 >= 12
 * Enter two integers to compare: 7 7
 * 7 == 7
 * 7 <= 7
 * 7 >= 7
 */
