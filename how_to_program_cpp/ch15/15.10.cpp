// Fig. 15.10: Fig15_10.cpp
// Standard Library vector class template
#include <iostream>
#include <vector>

template <typename T> void printVector(const std::vector<T> &integers2);

int main() {
    constexpr size_t SIZE{6};
    constexpr int values[SIZE]{1, 2, 3, 4, 5, 6};
    std::vector<int> integers;

    std::cout << "The initial size of integers is: " << integers.size()
              << "\nThe initial capacity of integers is: "
              << integers.capacity();

    integers.push_back(2);
    integers.push_back(3);
    integers.push_back(4);

    std::cout << "\nThe size of integers is: " << integers.size()
              << "\nThe capacity of integers is: " << integers.capacity();

    std::cout << "\n\nOutput built-in array using pointer notation: ";
    for (const int *ptr = std::cbegin(values); ptr != std::cend(values); ++ptr)
        std::cout << *ptr << ' ';

    std::cout << "\nOutput vector using iterator notation: ";
    printVector(integers);

    std::cout << "\nReverse contents of vector integers: ";
    // replace auto to explicit type
    for (std::vector<int>::const_reverse_iterator reverseIterator =
             integers.crbegin();
         reverseIterator != integers.crend(); ++reverseIterator)
        std::cout << *reverseIterator << ' ';

    std::cout.put('\n');
}

template <typename T> void printVector(const std::vector<T> &integers2) {
    // this auto have to be auto, because of this is a function with template
    for (auto constIterator = integers2.cbegin();
         constIterator != integers2.cend(); ++constIterator)
        std::cout << *constIterator << ' ';
    std::cout << "| ";
    // equivalent to
    for (T const &ref : integers2)
        std::cout << ref << ' ';
}

/* execution result
 * The initial size of integers is: 0
 * The initial capacity of integers is: 0
 * The size of integers is: 3
 * The capacity of integers is: 4
 *
 * Output built-in array using pointer notation: 1 2 3 4 5 6
 * Output vector using iterator notation: 2 3 4
 * Reverse contents of vector integers: 4 3 2
 */
