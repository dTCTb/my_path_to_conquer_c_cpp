// Fig. 16.4: fig16_04.cpp
// Algorithms replace, replace_if, replace_copy, replace_copy_if
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

constexpr size_t SIZE{10};
using intArr10 = std::array<int, SIZE>;
std::ostream_iterator<int> output{std::cout, " "};
bool greater9(int x) { return x > 9; }

void prompt(std::array<int, SIZE> arr, const char *prompt) {
    std::cout << prompt;
    std::copy(arr.cbegin(), arr.cend(), output);
}

int main() {
    constexpr intArr10 init{10, 2, 10, 4, 16, 6, 14, 8, 12, 10};

    intArr10 a1{init};
    prompt(a1, "a1 before replacing all 10s:\n   ");
    std::replace(a1.begin(), a1.end(), 10, 100);
    prompt(a1, "\na1 after replacing 10s with 100s:\n   ");

    intArr10 a2{init}, c1{};
    prompt(a2, "\n\na2 before replacing all 10s and copying:\n   ");
    std::replace_copy(a2.cbegin(), a2.cend(), c1.begin(), 10, 100);
    prompt(c1, "\nc1 after replacing all 10s in a2:\n   ");

    intArr10 a3{init};
    prompt(a3, "\n\na3 before replacing values greater than 9:\n   ");
    std::replace_if(a3.begin(), a3.end(), greater9, 100);
    prompt(a3, "\na3 after replacing all values greater"
               "\nthan 9 with 100s:\n   ");

    intArr10 a4{init}, c2{};
    prompt(a4, "\n\na4 before replacing all values greater "
               "than 9 and copying:\n   ");
    std::replace_copy_if(a4.cbegin(), a4.cend(), c2.begin(), greater9, 100);
    prompt(c2, "\nc2 after replacing all values greater than 9 in a4:\n   ");

    std::cout.put('\n');
}

/* execution result
a1 before replacing all 10s:
   10 2 10 4 16 6 14 8 12 10
a1 after replacing 10s with 100s:
   100 2 100 4 16 6 14 8 12 100

a2 before replacing all 10s and copying:
   10 2 10 4 16 6 14 8 12 10
c1 after replacing all 10s in a2:
   100 2 100 4 16 6 14 8 12 100

a3 before replacing values greater than 9:
   10 2 10 4 16 6 14 8 12 10
a3 after replacing all values greater
than 9 with 100s:
   100 2 100 4 100 6 100 8 100 100

a4 before replacing all values greater than 9 and copying:
   10 2 10 4 16 6 14 8 12 10
c2 after replacing all values greater than 9 in a4:
   100 2 100 4 100 6 100 8 100 100
*/
