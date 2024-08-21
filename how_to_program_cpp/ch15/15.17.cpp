// Fig. 15.17: fig15_17.cpp
// Standard Library multimap class template
#include <iostream>
#include <map>
// using namespace std;

typedef std::multimap<int, double, std::less<int>> mmapID;

int main() {
    // std::multimap<int, double, std::less<int>> pairs;
    mmapID pairs;

    std::cout << "There are currently " << pairs.count(15)
              << " pairs with key 15 in the multimap\n";

    pairs.insert(std::make_pair(15, 2.7));
    pairs.insert(std::make_pair(15, 99.3));

    std::cout << "After inserts, there are " << pairs.count(15)
              << " pairs with key 15\n\n";

    pairs.insert(std::make_pair(30, 111.11));
    pairs.insert(std::make_pair(10, 22.22));
    pairs.insert(std::make_pair(25, 33.333));
    pairs.insert(std::make_pair(20, 9.345));
    pairs.insert(std::make_pair(5, 77.54));

    std::cout << "Multimap pairs contains:\nKey\tValue\n";

    // for (auto mapItem : pairs)
    // for (const std::multimap<int, double, std::less<int>>::value_type
    // &mapItem : pairs)
    for (const mmapID::value_type &mapItem : pairs)
        std::cout << mapItem.first << '\t' << mapItem.second << '\n';
}

/* execution result
 * There are currently 0 pairs with key 15 in the multimap
 * After inserts, there are 2 pairs with key 15
 *
 * Multimap pairs contains:
 * Key     Value
 * 5       77.54
 * 10      22.22
 * 15      2.7
 * 15      99.3
 * 20      9.345
 * 25      33.333
 * 30      111.11
 */
