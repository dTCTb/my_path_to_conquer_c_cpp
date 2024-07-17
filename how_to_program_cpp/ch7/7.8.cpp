// Fig. 7.8: fig07_08.cpp
// Compute the sum of the elements of an array.
#include <array>
#include <iostream>
using namespace std;

int main() {
    const size_t arraySize = 4; // specifies size of array
    array<int, arraySize> a{10, 20, 30, 40};
    int total = 0;

    for (size_t i = 0; i < a.size(); ++i)
        total += a[i];

    cout << "Total of array elements: " << total << endl;
    return 0;
}
/* execution result
 * Total of array elements: 100
 */
