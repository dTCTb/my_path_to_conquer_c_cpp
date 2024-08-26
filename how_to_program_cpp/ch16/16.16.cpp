// Fig. 16.16: fig16_16.cpp
// Lambda expressions
#include <algorithm>
#include <array>
#include <iostream>

int main() {
    constexpr size_t SIZE{4};
    std::array<int, SIZE> values{1, 2, 3, 4};

    std::for_each(values.cbegin(), values.cend(),
                  [](const int &x) { std::cout << x * 2 << '\n'; });

    int sum{};

    std::for_each(values.cbegin(), values.cend(),
                  [&sum](const int &x) { return sum += x; });

    std::cout << "sum is " << sum << '\n';
}

/* execution result
 * 2
 * 4
 * 6
 * 8
 * sum is 10
 */
