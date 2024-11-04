#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static string compressedString(const string &word) noexcept {
        string ret;
        ret.reserve(word.size() /* * 2 */);
        char c{word[0]};
        unsigned char n{};

        for (const char &w : word) {
            if (w != c || n == 9) {
                ret.push_back(n + 48);
                ret.push_back(c);
                n = 0;
                c = w;
            }
            ++n;
        }
        ret.push_back(n + 48);
        ret.push_back(c);
        return ret;
    }
};

int main() {
    function<void(const string &, const string &)> test =
        [](const string &word, const string &answer) -> void {
        string myAnswer = Solution::compressedString(word);
        cout << "compress \"" << word << "\" to " << "\"" << myAnswer << '\"';
        cout << (answer == myAnswer ? "is " : "is not ") << "correct\n";
    };
    test("abcde", "1a1b1c1d1e");
    test("aaaaaaaaaaaaaabb", "9a5a2b");
    test("o", "1o");
    test("vvv", "3v");
    test("xxlaa", "2x1l2a");
    test("xbbbbjj", "1x4b2j");
    test("yyyyyyyyfffccccqqwwffffffffrrrrrrrrraaaaayyyyyyyyy",
         "8y3f4c2q2w8f9r5a9y");
    test("uuuuuuuuuuccccccvvvvvvvyyyyyyyylyyyqqqqqqqqqoaqqqq",
         "9u1u6c7v8y1l3y9q1o1a4q");
}
