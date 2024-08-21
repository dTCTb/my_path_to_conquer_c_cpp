// Fig. 15.11: fig15_11.cpp
// Testing Standard Library vector class template
// element-manipulation functions
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
    constexpr size_t SIZE{6};
    std::array<int, SIZE> values{1, 2, 3, 4, 5, 6};
    std::vector<int> integers{values.cbegin(), values.cend()};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Vector integers contains: ";
    std::copy(integers.cbegin(), integers.cend(), output);
    std::cout << "\nFirst element of integers: " << integers.front()
              << "\nLast element of integers: " << integers.back();

    integers[0] = 7;
    integers.at(2) = 10;

    integers.insert(integers.cbegin() + 1, 22);

    std::cout << "\n\nContents of vector integers after changes: ";
    std::copy(integers.cbegin(), integers.cend(), output);

    try {
        integers.at(100) = 777;
    } catch (out_of_range &ex) {
        std::cout << "\n\nException: " << ex.what();
    }

    integers.erase(integers.cbegin());
    std::cout << "\n\nVector integers after erasing first element: ";
    std::copy(integers.cbegin(), integers.cend(), output);

    integers.erase(integers.cbegin(), integers.cend());
    std::cout << "\nAfter erasing all elements, vector integers "
              << (integers.empty() ? "is" : "is not") << " empty";

    integers.insert(integers.cbegin(), values.cbegin(), values.cend());
    std::cout << "\n\nContents of vector integers before clear: ";
    std::copy(integers.cbegin(), integers.cend(), output);

    integers.clear();
    std::cout << "\nAfter clear, vector integers "
              << (integers.empty() ? "is" : "is not") << " empty\n";
}

/* execution result
 * Vector integers contains: 1 2 3 4 5 6
 * First element of integers: 1
 * Last element of integers: 6
 *
 * Contents of vector integers after changes: 7 22 2 10 4 5 6
 *
 * Exception: vector
 *
 * Vector integers after erasing first element: 22 2 10 4 5 6
 * After erasing all elements, vector integers is empty
 *
 * Contents of vector integers before clear: 1 2 3 4 5 6
 * After clear, vector integers is empty
 */
