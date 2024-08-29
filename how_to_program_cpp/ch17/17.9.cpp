// Fig. 17.9: fig17_09.cpp
// Demonstrating unique_ptr
#include "./Integer.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "Creating a unique_ptr object that points to an Integer\n";

    // "aim" unique_ptr at Integer object
    std::unique_ptr<Integer> ptrToInteger{new Integer{7}};

    std::cout << "\nUsing the unique_ptr to manipulate the Integer\n";
    ptrToInteger->setInteger(99);

    std::cout << "Integer after setInteger: " << ptrToInteger->getInteger()
              << "\n\nTerminating program\n";
}

/* execution result
Creating a unique_ptr object that points to an Integer
Constructor for Integer 7

Using the unique_ptr to manipulate the Integer
Integer after setInteger: 99

Terminating program
Destructor for Integer 99
*/
