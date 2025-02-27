// Fig. 7.12: fig07_12.cpp
// static array initialization and automic array initialization.
#include <array>
#include <iostream>
using namespace std;

void staticArrayInit();
void automaticArrayInit();
const size_t arraySize = 3;

int main() {
    cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    cout << "\n\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
    return 0;
}

void staticArrayInit(void) {
    static array<int, arraySize> array1;
    cout << "\nValues on entering staticArrayInit:\n";
    for (size_t i = 0; i < array1.size(); i++)
        cout << "array1[" << i << "] = " << array1[i] << " ";
    cout << "\nValues on exiting staticArrayInit:\n";
    for (size_t j = 0; j < array1.size(); j++)
        cout << "array1[" << j << "] = " << (array1[j] += 5) << " ";
}

void automaticArrayInit(void) {
    array<int, arraySize> array2{1, 2, 3};
    cout << "\n\nValues on entering automaticArrayInit:\n";
    for (size_t i = 0; i < array2.size(); i++)
        cout << "array2[" << i << "] = " << array2[i] << " ";
    cout << "\nValues on exiting automaticArrayInit:\n";
    for (size_t j = 0; j < array2.size(); j++)
        cout << "array2[" << j << "] = " << (array2[j] += 5) << " ";
}
/* execution result
 * First call to each function:
 *
 * Values on entering staticArrayInit:
 * array1[0] = 0 array1[1] = 0 array1[2] = 0
 * Values on exiting staticArrayInit:
 * array1[0] = 5 array1[1] = 5 array1[2] = 5
 *
 * Values on entering automaticArrayInit:
 * array2[0] = 1 array2[1] = 2 array2[2] = 3
 * Values on exiting automaticArrayInit:
 * array2[0] = 6 array2[1] = 7 array2[2] = 8
 *
 * Second call to each function:
 *
 * Values on entering staticArrayInit:
 * array1[0] = 5 array1[1] = 5 array1[2] = 5
 * Values on exiting staticArrayInit:
 * array1[0] = 10 array1[1] = 10 array1[2] = 10
 *
 * Values on entering automaticArrayInit:
 * array2[0] = 1 array2[1] = 2 array2[2] = 3
 * Values on exiting automaticArrayInit:
 * array2[0] = 6 array2[1] = 7 array2[2] = 8
 */
