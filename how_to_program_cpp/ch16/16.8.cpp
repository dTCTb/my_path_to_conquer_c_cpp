// Fig. 16.8: fig16_08.cpp
// Algorithms copy_backward, merge, unique and reverse
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

constexpr size_t SIZE{5};
using i_Arr5 = std::array<int, SIZE>;
std::ostream_iterator<int> output{std::cout, " "};

int main() {
    i_Arr5 a1{1, 3, 5, 7, 9};
    i_Arr5 a2{2, 4, 5, 7, 9};

    std::cout << "array a1 contains: ";
    std::copy(a1.cbegin(), a1.cend(), output);
    std::cout << "\narray a2 contains: ";
    std::copy(a2.cbegin(), a2.cend(), output);

    i_Arr5 results;
    std::copy_backward(a1.cbegin(), a1.cend(), results.end());
    std::cout << "\n\nAfter copy_backward, results contains: ";
    std::copy(results.cbegin(), results.cend(), output);

    std::array<int, SIZE + SIZE> results2;
    std::merge(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(),
               results2.begin());
    std::cout << "\n\nAfter merge of a1 and a2 results2 contains: ";
    std::copy(results2.cbegin(), results2.cend(), output);

    std::array<int, SIZE + SIZE>::const_iterator endLocation =
        std::unique(results2.begin(), results2.end());
    std::cout << "\n\nAfter unique results2 contains: ";
    std::copy(results2.cbegin(), endLocation, output);

    std::cout << "\n\narray a1 after reverse: ";
    std::reverse(a1.begin(), a1.end());
    std::copy(a1.cbegin(), a1.cend(), output);

    std::cout.put('\n');
}

/* execution result
array a1 contains: 1 3 5 7 9
array a2 contains: 2 4 5 7 9

After copy_backward, results contains: 1 3 5 7 9

After merge of a1 and a2 results2 contains: 1 2 3 4 5 5 7 7 9 9

After unique results2 contains: 1 2 3 4 5 7 9

array a1 after reverse: 9 7 5 3 1
*/
