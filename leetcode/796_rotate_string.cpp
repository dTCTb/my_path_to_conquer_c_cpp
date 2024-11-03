#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static bool rotateString(const string &s, const string &goal) {
        if (s.size() != goal.size())
            return false;
        if (s == goal)
            return true;

        size_t sep{};
        for (size_t i{}; i + sep < s.size();)
            if (s[i + sep] == goal[sep])
                ++sep;
            else
                sep = 0, ++i;

        cout << s.substr(0, s.size() - sep) << '\n' << goal.substr(sep) << '\n';
        if (s.substr(0, s.size() - sep) == goal.substr(sep))
            return true;
        else /* if (j == 0) */
            return false;
    }

    // omg, I don't even notice (very good observation,
    //                but this method has zero technique on string manipulation)
    static bool rotateString_oneline(const string &s, const string &goal) {
        return s.size() == goal.size() && (goal + goal).find(s) != string::npos;
    }
};

int main() {
    function<void(const string &, const string &, bool)> test =
        [](const string &s, const string &goal, const bool answer) {
            bool myAnswer = Solution::rotateString(s, goal);
            if (myAnswer == answer)
                cout << "Correct, " << myAnswer << '\n';
            else
                cout << "Incorrect, my answer is " << myAnswer
                     << ", but correct answer is " << answer << '\n';
        };
    cout << boolalpha;
    test("abcde", "cdeab", true);
    test("abcde", "abced", false);
    test("a", "a", true);
    test("bcad", "cdba", false);
    test("bcad", "abcd", false);
    test("abcd", "cdeab", false);
    test("abcde", "abce", false);
    test("bbbacddceeb", "ceebbbbacdd", true);
    test("abcdebcdefin", "abcdebcdefin", true);
    test("dvadererrerdvaddf", "rerdvaddfdvaderer", true);
    test("xjab", "abcd", false);
}
