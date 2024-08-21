// Fig. 16.1: fig16_01.cpp
// Algorithms fill, fill_n, generate and generate_n
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
using std::copy, std::cout, std::array, std::ostream_iterator;
ostream_iterator<char> output{cout, " "};
char nextLetter();

template <typename T = char, int num = 10>
auto textLine(const char *tl, std::array<T, num> &chars) -> void {
    cout << tl;
    copy(chars.cbegin(), chars.cend(), output);
}

int main() {
    array<char, 10> chars;

    std::fill(chars.begin(), chars.end(), '5');
    textLine<char, 10>("chars after filling with 5s:\n", chars);

    std::fill_n(chars.begin(), 5, 'A');
    textLine<char, 10>("\n\nchars after filling five elements with As:\n",
                       chars);

    std::generate(chars.begin(), chars.end(), nextLetter);
    textLine<char, 10>("\n\nchars after generating letters A-J:\n", chars);

    std::generate_n(chars.begin(), 5, nextLetter);
    textLine<char, 10>(
        "\n\nchars after genearting K-O for the first five elements:\n", chars);

    cout.put('\n');
}

char nextLetter() {
    static char letter = 'A';
    if (letter == 'Z' + 1) // prevent generated an char that exceeding alphabet
        letter = 'A';
    return letter++;
}

/* execution result
 * chars after filling with 5s:
 * 5 5 5 5 5 5 5 5 5 5
 *
 * chars after filling five elements with As:
 * A A A A A 5 5 5 5 5
 *
 * chars after generating letters A-J:
 * A B C D E F G H I J
 *
 * chars after genearting K-O for the first five elements:
 * K L M N O F G H I J
 */
