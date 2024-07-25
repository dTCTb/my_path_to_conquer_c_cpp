// Fig. 8.4: fig08_04.cpp
// Pointer operators & and *
#include <iostream>

int main() {
    int a = 7;
    int *aPtr = &a;

    std::cout << "The address of a is " << &a << "\nThe value of aPtr is "
              << aPtr;
    std::cout << "\n\nThe value of a is " << a << "\nThe value of *aPtr is "
              << *aPtr << std::endl;
    return 0;
}
/* execution result
 * The address of a is 0x16dbf6d48
 * The value of aPtr is 0x16dbf6d48
 *
 * The value of a is 7
 * The value of *aPtr is 7
 */
