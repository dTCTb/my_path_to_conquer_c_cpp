// Fig. 15.18: fig15_18.cpp
// Standard Library class map template
#include <iostream>
#include <map>
// using namespace std;

typedef std::map<int, double, std::less<int>> mapID;

int main() {
    mapID pairs;

    pairs.insert(std::make_pair(15, 2.7));
    pairs.insert(std::make_pair(30, 111.11));
    pairs.insert(std::make_pair(5, 1010.1));
    pairs.insert(std::make_pair(10, 22.22));
    pairs.insert(std::make_pair(25, 33.333));
    pairs.insert(std::make_pair(5, 77.54));
    pairs.insert(std::make_pair(20, 9.345));
    pairs.insert(std::make_pair(15, 99.3));

    std::cout << "pairs contains:\nKey\tValue\n";

    for (auto &mapItem : pairs)
        std::cout << mapItem.first << '\t' << mapItem.second << '\n';

    pairs[25] = 9999.99;
    pairs[40] = 8765.43;

    std::cout << "\nAfter subscript operations, pairs contains:\nKey\tValue\n";

    for (const std::map<int, double, std::less<int>>::value_type &mapItem :
         pairs)
        std::cout << mapItem.first << '\t' << mapItem.second << '\n';
}

/* execution result
 * pairs contains:
 * Key     Value
 * 5       1010.1
 * 10      22.22
 * 15      2.7
 * 20      9.345
 * 25      33.333
 * 30      111.11
 *
 * After subscript operations, pairs contains:
 * Key     Value
 * 5       1010.1
 * 10      22.22
 * 15      2.7
 * 20      9.345
 * 25      9999.99
 * 30      111.11
 * 40      8765.43
 */
