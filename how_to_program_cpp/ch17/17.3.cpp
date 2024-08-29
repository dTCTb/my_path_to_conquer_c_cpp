// Fig. 17.3: fig17_03.cpp
// Rethrowing an exception
#include <exception>
#include <iostream>

void throwException() {
    try {
        std::cout << "   Function throwException throws an exception\n";
        throw std::exception(); // generate exception
    } catch (std::exception &) {
        std::cout << "   Exception handled in function throwException\n"
                     "   Function throwException rethrows exception";
        throw; // rethrow exceptionfor further processing
    }
    std::cout << "This also should not print\n";
}

int main() {
    try {
        std::cout << "\nmain invokes function throwException\n";
        throwException();
        std::cout << "This should not print\n";
    } catch (std::exception &) {
        std::cout << "\n\nException handled in main\n";
    }

    std::cout << "Program control continues after catch in main\n";
}

/* execution result
main invokes function throwException
   Function throwException throws an exception
   Exception handled in function throwException
   Function throwException rethrows exception

Exception handled in main
Program control continues after catch in main
*/
