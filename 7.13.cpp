// Fig. 7.13: fig07_13.cpp
// Using range-based for to multiply an array's elements by 2.
#include <array>
#include <iostream>
using namespace std;

int main() {
    array<int, 5> items{1, 2, 3, 4, 5};

    cout << "items before modification: ";
    for (int item : items)
        cout << item << " ";

    for (int &itemRef : items)
        itemRef *= 2;

    cout << "\nitems after modification: ";
    for (int item : items)
        cout << item << " ";
    cout << endl;
    return 0;
}
/* execution result
 * items before modification: 1 2 3 4 5
 * items after modification: 2 4 6 8 10
 */
