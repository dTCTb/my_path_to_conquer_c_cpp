// Fig. 17.5: fig17_05.cpp
// Demonstrating standard new throwing bad_alloc when memory cannot be allocated
#include <iostream>
#include <new>

int main() {
    double *ptr[50];

    try {
        for (std::size_t i = 0; i < 50; ++i) {
            ptr[i] = new double[5'000'000'000'000];
            std::cout << "ptr[" << i
                      << "] points to 5,000,000,000 new doubles\n";
        }
    } catch (std::bad_alloc &memoryAllocationException) {
        std::cerr << "Exception occurred: " << memoryAllocationException.what()
                  << '\n';
    }
}
/* execution result
ptr[0] points to 50,000,000 new doubles
ptr[1] points to 50,000,000 new doubles
Exception occurred: std::bad_alloc
*/
