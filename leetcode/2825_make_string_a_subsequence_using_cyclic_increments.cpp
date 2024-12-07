#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

using cStr = const string;
class Solution {
  public:
    static bool canMakeSubsequence(cStr &str1, cStr &str2) noexcept {
        function<char(char)> inc = [](char c) -> char {
            return (c + 1 - 'a') % 26 + 'a';
        };
        for (int i{}, j{}; j < str2.size(); ++i)
            if (i > str1.size())
                return false;
            else if (str1[i] == str2[j] || inc(str1[i]) == str2[j])
                ++j;

        return true;
    }

    static void print(const string &str) noexcept {
        function<char(char)> inc = [](char c) -> char {
            return (c + 1 - 'a') % 26 + 'a';
        };
        cout << str << " -> ";
        for (const char &c : str)
            cout.put(inc(c));
        cout.put('\n');
    }
};

typedef std::tuple<string, string, bool> testcases;

ostream &operator<<(ostream &c,
                    unordered_map<size_t, testcases>::value_type &p) {
    const auto &[no, testcase] = p;
    const auto &[str1, str2, answer] = testcase;
    c << "Testcase " << no << '\n';
    bool myAnswer = Solution::canMakeSubsequence(str1, str2);
    c << (myAnswer == answer ? "Correct" : "Incorrect") << '\n';
    c << "- -- - -- - -- -\n";
    return c;
}
int main() {
    unordered_map<size_t, testcases> testcases{
        {1, {"abc", "ad", true}},
        {2, {"zc", "ad", true}},
        {3, {"ab", "d", false}},
        {4, {"a", "d", false}},
        {5, {"b", "c", true}},
        {6, {"du", "ed", false}},
        {7, {"om", "nm", false}},
        {8, {"nbksekflejzgzhusd", "osellfjzgais", true}},
        {9,
         {"prcvufizgagxdxhtyojmeptiitqanwluhoafgbozjtknrvzr",
          "gyxtyckdxwzxptkjaqgnikqmlkefgooqrpxnzfexflizclfh", false}},
#include "./TestCases/2825_testcase.txt" // include testcases 10 & 11
    };
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
