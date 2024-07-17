// Fig. 7.10: fig07_10.cpp
// Die-rolling program using an array instead of switch.
#include <array>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

int main() {
    /* use the default random-number generation engine to produce uniformly
     * distributed pseudorandom int value from 1 to 6 */
    default_random_engine engine(static_cast<unsigned>(time(0)));
    uniform_int_distribution<unsigned> randomInt(1, 6);

    const size_t arraySize = 7;             // ignore element zero
    array<unsigned, arraySize> frequency{}; // initialize to 0s

    // roll die 6,000,000 times; use die value as frequency index
    for (unsigned roll = 1; roll <= 6000000; ++roll)
        ++frequency[randomInt(engine)];

    cout << "Face" << setw(13) << "Frequency" << endl;
    for (size_t face = 1; face < frequency.size(); ++face)
        cout << setw(4) << face << setw(13) << frequency[face] << endl;
}
/* execution result
 * Face    Frequency
 *    1      1000695
 *    2       999158
 *    3      1001185
 *    4       999643
 *    5       999183
 *    6      1000136
 */
