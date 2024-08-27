// Fig. 16.3: fig16_03.cpp
// Algorithms remove, remove_if, remove_copy and remove_copy_if
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

constexpr size_t SIZE{10};

using intArr10 = std::array<int, SIZE>;
using std::cout, std::copy;

std::ostream_iterator<int> output{std::cout, " "};

bool greater9(int x) { return x > 9; }

int main() {
    intArr10 init{10, 2, 10, 4, 16, 6, 14, 8, 12, 10};

    intArr10 a1{init};
    cout << "a1 before removing all 10s:\n   ";
    copy(a1.cbegin(), a1.cend(), output);

    intArr10::const_iterator newLastElement =
        std::remove(a1.begin(), a1.end(), 10);
    cout << "\na1 after removing all 10s:\n   ";
    copy(a1.cbegin(), newLastElement, output);

    intArr10 a2{init}, c{};
    cout << "\n\na2 before removing all 10s and copying:\n   ";
    copy(a2.cbegin(), a2.cend(), output);

    std::remove_copy(a2.cbegin(), a2.cend(), c.begin(), 10);
    cout << "\nc after removing all 10s from a2:\n   ";
    copy(c.cbegin(), c.cend(), output);

    intArr10 a3{init};
    cout << "\n\na3 before removing all elements greater than 9:\n   ";
    copy(a3.cbegin(), a3.cend(), output);

    newLastElement = std::remove_if(a3.begin(), a3.end(), greater9);
    cout << "\na3 after removing all elements greater than 9:\n   ";
    copy(a3.cbegin(), newLastElement, output);

    intArr10 a4{init}, c2{};
    cout << "\n\na4 before removing all elements"
         << "\ngreater than 9 and copying:\n   ";
    copy(a4.cbegin(), a4.cend(), output);

    std::remove_copy_if(a4.cbegin(), a4.cend(), c2.begin(), greater9);
    cout << "\nc2 after removing all elements\ngreater than 9 from a4:\n   ";
    copy(c2.cbegin(), c2.cend(), output);
    cout.put('\n');
}

/* execution result
a1 before removing all 10s:
   10 2 10 4 16 6 14 8 12 10
a1 after removing all 10s:
   2 4 16 6 14 8 12

a2 before removing all 10s and copying:
   10 2 10 4 16 6 14 8 12 10
c after removing all 10s from a2:
   2 4 16 6 14 8 12 0 0 0

a3 before removing all elements greater than 9:
   10 2 10 4 16 6 14 8 12 10
a3 after removing all elements greater than 9:
   2 4 6 8

a4 before removing all elements
greater than 9 and copying:
   10 2 10 4 16 6 14 8 12 10
c2 after removing all elements
greater than 9 from a4:
   2 4 6 8 0 0 0 0 0 0
*/
