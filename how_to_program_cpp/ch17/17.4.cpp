// Fig. 17.4: fig17_04.cpp
// Demonstrating stack unwinding
#include <iostream>
#include <stdexcept>

void function3() {
    std::cout << "In function 3\n";
    throw std::runtime_error("runtime_error in function3");
}

void function2() {
    std::cout << "function3 is called inside function2\n";
    function3();
}

void function1() {
    std::cout << "function2 is called inside function1\n";
    function2();
}

int main() {
    try {
        std::cout << "function1 is called inside main\n";
        function1();
    } catch (std::runtime_error &error) {
        std::cout << "Exception occurred: " << error.what() << '\n';
        std::cout << "Exception handled in main\n";
    }
}

/* execution result
function1 is called inside main
function2 is called inside function1
function3 is called inside function2
In function 3
Exception occurred: runtime_error in function3
Exception handled in main
*/
