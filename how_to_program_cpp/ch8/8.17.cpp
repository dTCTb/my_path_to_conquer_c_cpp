// Fig. 8.17: fig08_17.cpp
// Using subscripting and pointer notations with built-in arrays
#include <iostream>
using namespace std;

int main() {
    int b[] = {10, 20, 30, 40};
    int *bPtr = b;

    cout << "Array b displayed with:\n\nArray subscript notation\n";

    for (size_t i = 0; i < 4; i++)
        cout << "b[" << i << "] = " << b[i] << '\n';

    cout << "\nPointer/offset notation where the pointer is the array name\n";

    for (size_t offset1 = 0; offset1 < 4; offset1++)
        cout << "*(b + " << offset1 << ") = " << *(b + offset1) << '\n';

    cout << "\nPointer subscript notation\n";

    for (size_t j = 0; j < 4; j++)
        cout << "bPtr[" << j << "] = " << bPtr[j] << '\n';

    cout << "\nPointer/offset notation\n";

    for (size_t offset2 = 0; offset2 < 4; offset2++)
        cout << "*(bPtr + " << offset2 << ") = " << *(bPtr + offset2) << '\n';
    return 0;
}
/* execution result
 * Array b displayed with:
 *
 * Array subscript notation
 * b[0] = 10
 * b[1] = 20
 * b[2] = 30
 * b[3] = 40
 *
 * Pointer/offset notation where the pointer is the array name
 * *(b + 0) = 10
 * *(b + 1) = 20
 * *(b + 2) = 30
 * *(b + 3) = 40
 *
 * Pointer subscript notation
 * bPtr[0] = 10
 * bPtr[1] = 20
 * bPtr[2] = 30
 * bPtr[3] = 40
 *
 * Pointer/offset notation
 * *(bPtr + 0) = 10
 * *(bPtr + 1) = 20
 * *(bPtr + 2) = 30
 * *(bPtr + 3) = 40
 */
