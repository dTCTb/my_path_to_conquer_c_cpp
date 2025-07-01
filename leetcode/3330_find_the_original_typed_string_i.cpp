#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
  public:
    static int possibleStringCount(const string &word) {
        // return two_ptr_stack(word);
        return one_loop(word);
    }
    // clang-format off
    static int two_ptr_stack(const string word) {
        stack<char> sk;
        int ans{};
        for (const char ch : word)
            if      (sk.empty())     sk.push(ch);
            else if (sk.top() == ch) ++ans;
            else                     sk.push(ch);
        return ans + 1;
    }
    static int one_loop(const string word) {
        int ans{};
        for (int i{}; i < word.length() - 1; ++i)
            ans += word[i] == word[i + 1] ? 1 : 0;
        return ans + 1;
    }
};

int main() {
    Solution s = Solution{};
    cout << "ans: " << Solution::possibleStringCount("abbcccc") << '\n'; // 5
    cout << "ans: " << Solution::possibleStringCount("abcd") << '\n';    // 1
    cout << "ans: " << Solution::possibleStringCount("aaaa") << '\n';    // 4
    cout << "ans: " << Solution::possibleStringCount("ere") << '\n';     // 1
    cout << "ans: " << s.possibleStringCount("asd") << '\n';             // 1
}
