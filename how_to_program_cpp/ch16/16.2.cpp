// Fig. 16.2: fig16_02.cpp
// Algorithms equal, mismatch and lexicographical_compare
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
using std::cout, std::array, std::ostream_iterator, std::copy;

int main() {
    constexpr size_t SIZE{10};
    array<int, SIZE> a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, SIZE> a2{a1};
    array<int, SIZE> a3{1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
    ostream_iterator<int> output{cout, " "};

    cout << "a1 contains: ";
    copy(a1.cbegin(), a1.cend(), output);
    cout << "\na2 contains: ";
    copy(a2.cbegin(), a2.cend(), output);
    cout << "\na3 contains: ";
    copy(a3.cbegin(), a3.cend(), output);

    bool result = std::equal(a1.cbegin(), a1.cend(), a2.cbegin());
    cout << "\n\na1 " << (result ? "is" : "is not") << " equal to a2.\n";

    result = std::equal(a1.cbegin(), a1.cend(), a3.cbegin());
    cout << "a1 " << (result ? "is" : "is not") << " equal to a3.\n";

#if !defined CPP17
    // auto location = std::mismatch(a1.cbegin(), a1.cend(), a3.cbegin());
    std::pair<array<int, SIZE>::const_iterator,
              array<int, SIZE>::const_iterator>
        location = std::mismatch(a1.cbegin(), a1.cend(), a3.cbegin());
    cout << "\nThere is a mismatch between a1 and a3 at location "
         << (location.first - a1.begin()) << "\nwhere a1 contains "
         << *location.first << " and a3 contains " << *location.second
         << "\n\n";
#else
    auto [first, second] = std::mismatch(a1.cbegin(), a1.cend(), a3.cbegin());
    cout << "\nThere is a mismatch between a1 and a3 at location "
         << (first - a1.begin()) << "\nwhere a1 contains " << *first
         << " and a3 contains " << *second << "\n\n";
#endif

    char c1[SIZE] = "HELLO";
    char c2[SIZE] = "BYE BYE";

    result = std::lexicographical_compare(std::begin(c1), std::end(c1),
                                          std::begin(c2), std::end(c2));
    cout << c1 << (result ? " is less than " : " is greater than or equal to ")
         << c2 << std::endl;
}

/* execution result
 * a1 contains: 1 2 3 4 5 6 7 8 9 10
 * a2 contains: 1 2 3 4 5 6 7 8 9 10
 * a3 contains: 1 2 3 4 1000 6 7 8 9 10
 *
 * a1 is equal to a2.
 * a1 is not equal to a3.
 *
 * There is a mismatch between a1 and a3 at location 4
 * where a1 contains 5 and a3 contains 1000
 *
 * HELLO is greater than or equal to BYE BYE
 */
