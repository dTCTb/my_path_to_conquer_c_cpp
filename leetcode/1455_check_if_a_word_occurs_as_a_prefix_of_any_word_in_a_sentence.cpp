#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

typedef const std::string cStr;
class Solution {
  public:
    static int isPrefixOfWord(cStr sentence, cStr searchWord) noexcept {
        stringstream in{sentence};
        int ans{};
        string substr;
        while (in >> substr)
            if (++ans, substr.substr(0, searchWord.size()) == searchWord)
                return ans;
        return -1;
    }
};

typedef std::tuple<string, string, int> testcase;
typedef std::unordered_map<size_t, testcase> testcases;
auto test = bind(Solution::isPrefixOfWord, placeholders::_1, placeholders::_2);

ostream &operator<<(ostream &c, const testcases::value_type &pair) {
    auto &[no, testcase] = pair;
    auto &[sentence, searchWord, answer] = testcase;
    int myAnswer = test(sentence, searchWord);
    c << "Testcase " << no << '\n';
    c << sentence << " << " << searchWord << '\n';
    if (myAnswer == answer) {
        if (myAnswer != -1) {
            for (size_t i{}, w{1}, c{}; i < sentence.size(); ++i) {
                if (w == myAnswer) {
                    while (c++ < searchWord.size())
                        cout.put('^');
                    break;
                } else
                    cout.put(' ');
                w += sentence[i] == ' ' ? 1 : 0;
            }
            c << "\nCorrect. prefix " << quoted(searchWord) << " occurs at "
              << myAnswer << " word";
        } else
            c << "prefix " << quoted(searchWord)
              << " does not occurs in sentence";
    } else {
        c << "Incorrect. my answer " << quoted(to_string(myAnswer))
          << " but the correct answer is " << quoted(to_string(answer));
    }
    c << "\n- -- - -- - -- -\n";
    return c;
}

int main() {
    testcases testcases{{1, {"i love eating burger", "burg", 4}},
                        {2, {"this problem is an easy problem", "pro", 2}},
                        {3, {"i am tired", "you", -1}},
                        {4, {"i love eating bunburger burger", "burg", 5}},
                        {5, {"hellohello hellohellohello", "ello", -1}},
                        {6, {"i love eating broadburgers", "burg", -1}},
                        {7, {"love i love eating bunburger burger", "i", 2}},
                        {8, {"helloh hellohe", "hellohe", 2}},
                        {9,
                         {"winstontang love they i pillow jonathan you "
                          "winstontang pillow dream you duck",
                          "p", 5}},
                        {10, {"love", "lov", 1}},
                        {11, {"hello from the other side", "they", -1}}};
    cout << *testcases.find(1);
    cout << *testcases.find(2);
    cout << *testcases.find(3);
    cout << *testcases.find(4);
    cout << *testcases.find(5);
    cout << *testcases.find(6);
    cout << *testcases.find(7);
    cout << *testcases.find(8);
    cout << *testcases.find(9);
    cout << *testcases.find(10);
    cout << *testcases.find(11);
}
