// Fig. 15.15: fig15_15.cpp
// Standard Library multiset class template
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
// using namespace std;

int main() {
    constexpr size_t SIZE{10};
    std::array<int, SIZE> a{7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
    std::multiset<int, std::less<int>> intMultiset;
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "There are currently " << intMultiset.count(15)
              << " values of 15 in the multiset\n";

    intMultiset.insert(15);
    intMultiset.insert(15);
    std::cout << "After inserts, there are " << intMultiset.count(15)
              << " values of 15 in the multiset\n\n";

    auto result = intMultiset.find(15);

    if (result != intMultiset.end())
        std::cout << "Found value 15\n";

    result = intMultiset.find(20);

    if (result == intMultiset.end())
        std::cout << "Did not find value 20\n";

    intMultiset.insert(a.cbegin(), a.cend());
    std::cout << "\nAfter insert, intMultiset contains:\n";
    std::copy(intMultiset.begin(), intMultiset.end(), output);

    std::cout << "\n\nLower bound of 22: " << *(intMultiset.lower_bound(22));
    std::cout << "\nUpper bound of 22: " << *(intMultiset.upper_bound(22));

    // auto p = intMultiset.equal_range(22);
    std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> p =
        intMultiset.equal_range(22);

    std::cout << "\n\nequal_range of 22:" << "\n   Lower bound: " << *(p.first)
              << "\n   Upper bound: " << *(p.second);
    std::cout.put('\n');
}
/* execution result
 * There are currently 0 values of 15 in the multiset
 * After inserts, there are 2 values of 15 in the multiset
 *
 * Found value 15
 * Did not find value 20
 *
 * After insert, intMultiset contains:
 * 1 7 9 13 15 15 18 22 22 30 85 100
 *
 * Lower bound of 22: 22
 * Upper bound of 22: 30
 *
 * equal_range of 22:
 *    Lower bound: 22
 *    Upper bound: 30
 */
