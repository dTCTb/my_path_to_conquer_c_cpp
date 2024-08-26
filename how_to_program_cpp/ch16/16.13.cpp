// Fig. 16.13: fig16_13.cpp
// Algorithms min, max, minmax and minmax_element
#include <algorithm>
#include <array>
#include <iostream>
using std::cout, std::array, std::ostream_iterator, std::copy;

int main() {
    cout << "The minimum of 12 and 7 is: " << std::min(12, 7);
    cout << "\nThe maximum of 12 and 7 is: " << std::max(12, 7);
    cout << "\nThe minimum of 'G' and 'Z' is: " << std::min('G', 'Z');
    cout << "\nThe maximum of 'G' and 'Z' is: " << std::max('G', 'Z');

    std::pair<int, int> result1 = std::minmax(12, 7);
    cout << "\n\nThe minimum of 12 and 7 is: " << result1.first
         << "\nThe maximum of 12 and 7 is: " << result1.second;

    array<int, 10> items{3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
    cout << "\n\nArray items contains: ";
    copy(items.cbegin(), items.cend(), ostream_iterator<int>(cout, " "));
    auto [min, max] = std::minmax_element(items.cbegin(), items.cend());
    cout << "\nThe minimum element in items is: " << *min
         << "\nThe maximum element in items is: " << *max;

    cout.put('\n');
}

/* execution result
The minimum of 12 and 7 is: 7
The maximum of 12 and 7 is: 12
The minimum of 'G' and 'Z' is: G
The maximum of 'G' and 'Z' is: Z

The minimum of 12 and 7 is: 7
The maximum of 12 and 7 is: 12

Array items contains: 3 100 52 77 22 31 1 98 13 40
The minimum element in items is: 1
The maximum element in items is: 100
*/
