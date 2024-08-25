// clang-format off
// Fig. 16.11: fig16_11.cpp
// Algorithms lower_bound, upper_bound and equal_range for a sorted sequence of
// values
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

using std::cout, std::array;
constexpr size_t SIZE{10};
std::ostream_iterator<int> output(std::cout, " ");

void line(const char *const p1, int i, const char *const p2) {
    std::cout << p1 << i << p2;
}

int main() {
    array<int, SIZE> a{2, 2, 4, 4, 4, 6, 6, 6, 6, 8};
    cout << "array a contains:\n";
    std::copy(a.cbegin(), a.cend(), output);

    // std::lower_bound
    const int *lower = std::lower_bound(a.cbegin(), a.cend(), 6);
    line("\n\nLower bound of 6 is element ", (lower - a.cbegin()), " of array a");

    // std::upper_bound
    const int *upper = std::upper_bound(a.cbegin(), a.cend(), 6);
    line("\nUpper bound of 6 is element ", (upper - a.cbegin()), " of array a");

    // std::equal_range
    std::pair<const int *, const int *> pair_eq =
        std::equal_range(a.cbegin(), a.cend(), 6);
    cout << "\nUsing equal_range:";
    line("\n   Lower bound of 6 is element ", (pair_eq.first  - a.cbegin()), " of array a");
    line("\n   Upper bound of 6 is element ", (pair_eq.second - a.cbegin()), " of array a");

    // find value that not exists int array //

    cout << "\n\nUse lower_bound to locate the first point"
              "\nat which 5 can be inserted in order";
    lower = std::lower_bound(a.cbegin(), a.cend(), 5);
    line("\n   Lower bound of 5 is element ", (lower - a.begin()), " of array a");

    cout << "\n\nUse upper_bound to locate the last point"
         <<   "\nat which 7 can be inserted in order";
    upper = std::upper_bound(a.cbegin(), a.cend(), 7);
    line("\n   Upper bound of 7 is element ", (upper - a.cbegin()), " of array a");

    cout << "\n\nUse equal_range to locate the first and"
              "\nlast point at which 5 can be inserted in order";
    std::tuple<const int *, const int *> tuple_eq = std::equal_range(a.cbegin(), a.cend(), 5);
    const int *f = std::get<0>(tuple_eq);
    const int *s = std::get<1>(tuple_eq);
    line("\n   Lower bound of 5 is element ", (f - a.cbegin()), " of array a");
    line("\n   Upper bound of 5 is element ", (s - a.cbegin()), " of array a");

    cout.put('\n');
    return 0;
}

/* execution result
array a contains:
2 2 4 4 4 6 6 6 6 8

Lower bound of 6 is element 5 of array a
Upper bound of 6 is element 9 of array a
Using equal_range:
   Lower bound of 6 is element 5 of array a
   Upper bound of 6 is element 9 of array a

Use lower_bound to locate the first point
at which 5 can be inserted in order
   Lower bound of 5 is element 5 of array a

Use upper_bound to locate the last point
at which 7 can be inserted in order
   Upper bound of 7 is element 9 of array a

Use equal_range to locate the first and
last point at which 5 can be inserted in order
   Lower bound of 5 is element 5 of array a
   Upper bound of 5 is element 5 of array a
*/
