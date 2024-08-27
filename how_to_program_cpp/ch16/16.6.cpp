// Fig. 16.6: fig16_06.cpp
// Standard Library search and sort algorithms
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

constexpr size_t SIZE{10};
using i_Arr10 = std::array<int, SIZE>;
bool greater10(int value) { return value > 10; }

int main() {
    i_Arr10 a{10, 2, 17, 5, 16, 8, 13, 11, 20, 7};
    std::ostream_iterator<int> output{std::cout, " "};

    i_Arr10::const_iterator location;
    auto pFindRes = [&](const int t) noexcept {
        if (location != a.cend())
            std::cout << "\n\nFound " << t << " at location "
                      << (location - a.cbegin());
        else
            std::cout << "\n\n" << t << " not found";
    };

    // testing std::find
    std::cout << "array a contains: ";
    std::copy(a.cbegin(), a.cend(), output);
    location = std::find(a.cbegin(), a.cend(), 16);
    pFindRes(16);
    location = std::find(a.cbegin(), a.cend(), 100);
    pFindRes(100);

    // testing std::find_if
    location = std::find_if(a.cbegin(), a.cend(), [](int x) { return x > 10; });
    if (location != a.cend())
        std::cout << "\n\nThe first value greater than 10 is " << *location
                  << "\nfound at location " << (location - a.cbegin());
    else
        std::cout << "\n\nNo values greater than 10 were found";

    // testing std::sort
    std::sort(a.begin(), a.end());
    std::cout << "\n\narray a after sort: ";
    std::copy(a.cbegin(), a.cend(), output);

    // testing std::binary_search
    if (std::binary_search(a.cbegin(), a.cend(), 13))
        std::cout << "\n\n13 was found in a";
    else
        std::cout << "\n\n13 was not found in a";

    if (std::binary_search(a.cbegin(), a.cend(), 100))
        std::cout << "\n\n100 was found in a";
    else
        std::cout << "\n\n100 was not found in a";

    // testing std::all_of
    if (std::all_of(a.cbegin(), a.cend(), [](int x) { return x > 10; }))
        std::cout << "\n\nAll the elements in a are greater than 10";
    else
        std::cout << "\n\nSome of the elements in a are not greater than 10";
    // testing std::any_of
    if (std::any_of(a.cbegin(), a.cend(), [](int x) { return x > 10; }))
        std::cout << "\n\nSome of the elements in a are greater than 10";
    else
        std::cout << "\n\nSome elements in a are greater than 10";
    // testing std::none_of
    if (std::none_of(a.cbegin(), a.cend(), [](int x) { return x > 10; }))
        std::cout << "\n\nNone of the elements in a are greater than 10";
    else
        std::cout << "\n\nSome of the elements in a are greater than 10";

    // testing std::find_if_not
    location = std::find_if_not(a.cbegin(), a.cend(), greater10);
    if (location != a.cend())
        std::cout << "\n\nThe first value not greater than 10 is " << *location
                  << "\nfound at location " << (location - a.cbegin());
    else
        std::cout << "\n\nOnly values greater than 10 were found";

    std::cout.put('\n');
}

/* execution result
array a contains: 10 2 17 5 16 8 13 11 20 7

Found 16 at location 4
100 not found

The first value greater than 10 is 17
found at location 2

array a after sort: 2 5 7 8 10 11 13 16 17 20

13 was found in a
100 was not found in a

Some of the elements in a are not greater than 10

Some of the elements in a are greater than 10

Some of the elements in a are greater than 10

The first value not greater than 10 is 2
found at location 0
*/
