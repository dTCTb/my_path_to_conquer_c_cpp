// Fig. 16.5: fig16_05.cpp
// Mathematical algorithms of the Standard Library
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>

constexpr size_t SIZE{10};
using std::cout;
using intArr10 = std::array<int, SIZE>;

std::ostream &prompt(intArr10 &arr, const char *line, std::ostream &o = cout) {
    static std::ostream_iterator<int> output{cout, " "};
    cout << line;
    std::copy(arr.cbegin(), arr.cend(), output);
    return o;
}

bool greater9(int x) { return x > 9; }
void outputSquare(int x) { cout << x * x << ' '; }
int calculateCube(int x) { return x * x * x; }

int main() {
    std::random_device r;
    intArr10 a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    prompt(a1, "a1 before random_shuffle: ");
    std::shuffle(a1.begin(), a1.end(), std::default_random_engine{r()});
    prompt(a1, "\na1 after random_shuffle: ");

    intArr10 a2{100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
    prompt(a2, "\n\na2 contains: ");
    int result = std::count(a2.cbegin(), a2.cend(), 8);
    cout << "\nNumber of elements matching 8: " << result;
    result = std::count_if(a2.cbegin(), a2.cend(), greater9);
    cout << "\nNumber of elements greater than 9: " << result;

    cout << "\n\nMinimum element in a2 is: "
         << *(std::min_element(a2.cbegin(), a2.cend()));

    cout << "\nMaximum element in a2 is: "
         << *(std::max_element(a2.cbegin(), a2.cend()));
#if !defined CPP17
    // auto minAndMax = std::minmax_element(a2.cbegin(), a2.cend());
    std::pair<const int *, const int *> minAndMax =
        std::minmax_element(a2.cbegin(), a2.cend());
    cout << "\nThe minimum and maximum elements in a2 are "
         << *(minAndMax.first) << " and " << *(minAndMax.second)
         << ", respectively";
#else
    auto [min, max] = std::minmax_element(a2.cbegin(), a2.cend());
    cout << "\nThe minimum and maximum elements in a2 are " << *min << " and "
         << *max << ", respectively";
#endif

    cout << "\n\nThe total of the elements in a1 is: "
         << std::accumulate(a1.cbegin(), a1.cend(), 0);

    cout << "\n\nThe square of every integer in a1 is:\n";
    std::for_each(a1.cbegin(), a1.cend(), outputSquare);

    intArr10 cubes;

    std::transform(a1.cbegin(), a1.cend(), cubes.begin(), calculateCube);
    prompt(cubes, "\n\nThe cube of every integer is a1 is:\n");

    cout.put('\n');
}

/* execution result
a1 before random_shuffle: 1 2 3 4 5 6 7 8 9 10
a1 after random_shuffle: 2 7 1 4 3 6 5 10 9 8

a2 contains: 100 2 8 1 50 3 8 8 9 10
Number of elements matching 8: 3
Number of elements greater than 9: 3

Minimum element in a2 is: 1
Maximum element in a2 is: 100
The minimum and maximum elements in a2 are 1 and 100, respectively

The total of the elements in a1 is: 55

The square of every integer in a1 is:
4 49 1 16 9 36 25 100 81 64

The cube of every integer is a1 is:
8 343 1 64 27 216 125 1000 729 512
*/
