// clang-format off
// Fig. 7.18: fig07_18.cpp
// Sorting and searching arrays
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
using namespace std;

int main() {
    const size_t arraySize = 7; // size of array colors
    array<string, arraySize> colors = {"red",  "orange", "yellow", "green",
                                       "blue", "indigo", "violet"};
    // output original array
    cout << "Unsorted array:\n";
    for (string color : colors) cout << color << ' ';

    sort(colors.begin(), colors.end()); // sort contents of colors

    // output sorted array
    cout << "\nSorted array:\n";
    for (string item : colors) cout << item << ' ';

    // search for "indigo" in colors
    bool found = binary_search(colors.begin(), colors.end(), "indigo");
    cout << "\n\n\"indigo\" " << (found ? "was" : "was not")
         << " found in colors" << endl;

    // search for "cyan" in colors
    found = binary_search(colors.begin(), colors.end(), "cyan");
    cout << "\"cyan\" " << (found ? "was" : "was not") << " found in colors\n";

    return 0;
}
/* execution result
 * Unsorted array:
 * red orange yellow green blue indigo violet
 * Sorted array:
 * blue green indigo orange red violet yellow
 *
 * "indigo" was found in colors
 * "cyan" was not found in colors
 */
