// Fig. 15.16: fig15_16.cpp
// Standard Library set class template
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>

int main() {
    constexpr size_t SIZE{5};
    std::array<double, SIZE> a{2.1, 4.2, 9.5, 2.1, 3.7};
    std::set<double, std::less<double>> doubleSet{a.begin(), a.end()};
    std::ostream_iterator<double> output{std::cout, " "};

    std::cout << "doubleSet contains: ";
    std::copy(doubleSet.cbegin(), doubleSet.cend(), output);

    // auto p = doubleSet.insert(13.8);
    std::pair<std::set<double>::iterator, bool> p = doubleSet.insert(13.8);
    std::cout << "\n\n"
              << *(p.first) << (p.second ? " was" : " was not") << " inserted";
    std::cout << "\ndoubleSet contains: ";
    std::copy(doubleSet.cbegin(), doubleSet.cend(), output);

    p = doubleSet.insert(9.5);
    std::cout << "\n\n"
              << *(p.first) << (p.second ? " was" : " was not") << " inserted";
    std::cout << "\ndoubleSet contains: ";
    std::copy(doubleSet.cbegin(), doubleSet.cend(), output);

    std::cout.put('\n');
}

/* execution result
 * doubleSet contains: 2.1 3.7 4.2 9.5
 *
 * 13.8 was inserted
 * doubleSet contains: 2.1 3.7 4.2 9.5 13.8
 *
 * 9.5 was not inserted
 * doubleSet contains: 2.1 3.7 4.2 9.5 13.8
 */
