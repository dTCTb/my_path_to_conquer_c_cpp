// Fig. 17.6: fig17_06.cpp
// Demonstrating set_new_handler
#include <cstdlib> // abort function prototype
#include <iostream>
#include <new> // set_new_handler function prototype

// handle memory allocation failure
void customNewHandler() {
    std::cerr << "customNewHandler was called";
    abort();
}

// using set_new_handler to handle failed memory allocation
int main() {
    double *ptr[50];

    // specify that customNewHandler should be called on memory allocation
    // failure
    std::set_new_handler(customNewHandler);

    // aim each ptr[i] at a big block of memory; customNewHandler will be called
    // on failed memory allocation
    for (std::size_t i = 0; i < 50; ++i) {
        ptr[i] = new double[5'000'000'000'000];
        std::cout << "ptr[" << i << "] points to 5,000,000,000 new doubles\n";
    }
}

/* execution result
ptr[0] points to 5,000,000,000 new doubles
ptr[1] points to 5,000,000,000 new doubles
customNewHandler was calledzsh: abort      ./bin/17.6
 */
