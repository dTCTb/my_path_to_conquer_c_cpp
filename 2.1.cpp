// Fig. 2.1: fig02_1.cpp
// Text-printing program.
#include <iostream> // allows program to output data to the screen

// function main begins program execution
int main() {
    std::cout << "Welcome to C++!\n"; // display message
    // Fig. 2.3: Printing a line of text with multiple statements.
    std::cout << "Welcome ";
    std::cout << "to C++!\n";
    // Fig. 2.4: Printing multiple lines of text with a single statements.
    std::cout << "Welcome\nto\nC++!\n";

    return 0; // indicate that program ended successfully
} // end function main
/* execution result
 * Welcome to C++!
 * Welcome to C++!
 * Welcome
 * to
 * C++!
 */
