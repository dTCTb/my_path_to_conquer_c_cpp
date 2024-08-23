// Fig. 16.7: fig16_07.cpp
// Algorithms iter_swap, swap and swap_ranges
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

constexpr size_t SIZE{10};
using i_Arr10 = std::array<int, SIZE>;
void prompt(i_Arr10 &arr, const char *const line) {
    static std::ostream_iterator<int> output{std::cout, " "};
    std::cout << line;
    std::copy(arr.cbegin(), arr.cend(), output);
}

int main() {
    i_Arr10 a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    prompt(a, "Array a contains:\n   ");

    std::swap(a[0], a[1]);
    prompt(a, "\nArray a after swapping a[0] and a[1] using swap:\n   ");

    std::iter_swap(a.begin(), a.begin() + 1);
    prompt(a, "\nArray a after swapping a[0] and a[1] using iter_swap:\n   ");

    std::swap_ranges(a.begin(), a.begin() + 5, a.begin() + 5);
    prompt(a, "\nArray a after swapping the first five elements\n"
              "with the last five elements:\n   ");

    std::cout.put('\n');
}

/* execution result
Array a contains:
   1 2 3 4 5 6 7 8 9 10
Array a after swapping a[0] and a[1] using swap:
   2 1 3 4 5 6 7 8 9 10
Array a after swapping a[0] and a[1] using iter_swap:
   1 2 3 4 5 6 7 8 9 10
Array a after swapping the first five elements
with the last five elements:
   6 7 8 9 10 1 2 3 4 5
*/
