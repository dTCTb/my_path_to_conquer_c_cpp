#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static int minChanges(const string &s) noexcept {
        size_t ret{};
        for (int i{}, j{1}; j < s.size(); i += 2, j += 2)
            if (s[i] != s[j])
                ++ret;
        return ret;
    }
};

int main() {
    function<void(const string &, size_t)> test = [](const string &s,
                                                     size_t answer) -> void {
        size_t myAnswer = Solution::minChanges(s);
        cout << "It is "
             << (myAnswer == answer ? "\033[32mcorrect\033[0m"
                                    : "\033[31mincorrect\033[0m")
             << " to make " << (myAnswer == answer ? myAnswer : answer)
             << " minimum step(s) of changes to make "
             << quoted("\033[35m" + s + "\033[0m") << " beautiful\n";
    };
    test("1001", 2);
    test("10", 1);
    test("0000", 0);
    test("000011000000", 0);
    test("111101101110", 3);
    test("101011000001", 3);
    test("00010100111000", 3);
    test("10010100000111001101011000000010110011", 8);
    test("010100000000000011100100000110001110000110101111111000000010001010110"
         "100010100101100101010110111000101001111001101111101111001011111010011"
         "101100111011010000001010001111101011110001010100111110011111001000010"
         "110101100001011101000010000011011000110000000101100010101000010100000"
         "000011100010111101001101010110101100111001101111100110111101110000010"
         "111000011110110101111110011000001010011101010101111100000011001010100"
         "111010001011101111011010000101010111000101010111100101111011011001010"
         "110011001011100000101010101110101010100100011110100001011001101010000"
         "0011111110000100111011100111",
         141);
}
