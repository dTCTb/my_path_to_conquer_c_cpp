// Fig. 16.9: fig16_09.cpp
// Algorithms inplace_merge, reverse_copy and unique copy
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

constexpr size_t SIZE{10};
template <typename T> void prompt(T arr, const char *const p) noexcept {
    static std::ostream_iterator<int> output{std::cout, " "};
    std::cout << p;
    std::copy(arr.cbegin(), arr.cend(), output);
}

int main() {
    std::array<int, SIZE> a1{1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
    prompt(a1, "array a1 contains: ");

    std::inplace_merge(a1.begin(), a1.begin() + 5, a1.end());
    prompt(a1, "\nAfter inplace_merge, a1 contains: ");

    std::vector<int> results1;
    std::unique_copy(a1.cbegin(), a1.cend(), std::back_inserter(results1));
    prompt(results1, "\nAfter unique_copy results1 contains: ");

    std::vector<int> results2;
    std::reverse_copy(a1.cbegin(), a1.cend(), std::back_inserter(results2));
    prompt(results2, "\nAfter reverse_copy, results2 contains: ");

    std::cout.put('\n');
}

/* execution result
array a1 contains: 1 3 5 7 9 1 3 5 7 9
After inplace_merge, a1 contains: 1 1 3 3 5 5 7 7 9 9
After unique_copy results1 contains: 1 3 5 7 9
After reverse_copy, results2 contains: 9 9 7 7 5 5 3 3 1 1
*/
