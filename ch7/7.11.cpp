// Fig. 7.11: fig07_11.cpp
// Poll analysis program.
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    // define array sizes
    const size_t responseSize = 20;
    const size_t frequencySize = 6;

    // place survey responses in array responses
    const array<unsigned, responseSize> response{1, 2, 5, 4, 3, 5, 2, 1, 3, 1,
                                                 4, 3, 3, 3, 2, 3, 3, 2, 2, 5};
    array<unsigned, frequencySize> frequency{};

    for (size_t answer = 0; answer < response.size(); answer++)
        ++frequency[response[answer]];

    cout << "Rating" << setw(17) << "Frequency" << endl;

    for (size_t rating = 1; rating < frequency.size(); ++rating)
        cout << setw(6) << rating << setw(17) << frequency[rating] << endl;
    return 0;
}
/* execution result
 * Rating        Frequency
 *      1                3
 *      2                5
 *      3                7
 *      4                2
 *      5                3
 */
