// Fig. 16.15: fig16_15.cpp
// Demonstrating function objects
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

int sumSquares(int total, int value) { return total + value * value; }

template <typename T> class SumSquaresClass {
  public:
    T operator()(const T &total, const T &value) {
        return total + value * value;
    }
};

int main() {
    constexpr size_t SIZE{10};
    std::array<int, SIZE> integers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "array integers contains:\n";
    std::copy(integers.cbegin(), integers.cend(), output);

    int result =
        std::accumulate(integers.cbegin(), integers.cend(), 0, sumSquares);
    std::cout << "\n\nSum of squares of elements in integers using binary\n"
                 "function sumSquares: "
              << result;

    result = std::accumulate(integers.cbegin(), integers.cend(), 0,
                             SumSquaresClass<int>());
    std::cout << "\n\nSum of squares of elements in integers using binary\n"
                 "function object of type SumSquaresClass<int>: "
              << result;

    std::cout.put('\n');
}

/* execution result
array integers contains:
1 2 3 4 5 6 7 8 9 10

Sum of squares of elements in integers using binary
function sumSquares: 385

Sum of squares of elements in integers using binary
function object of type SumSquaresClass<int>: 385
 */
