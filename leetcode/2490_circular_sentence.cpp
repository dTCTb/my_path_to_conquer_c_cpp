#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static bool isCircularSentence(const string &sentence) noexcept {
        if (sentence.front() != sentence.back())
            return false;

        for (size_t i{}; i < sentence.size(); ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        }

        return true;
    }
};

int main() {
    cout << boolalpha;
    cout << Solution::isCircularSentence("L") << '\n';
    cout << Solution::isCircularSentence("sus") << '\n';
    cout << Solution::isCircularSentence("leetcode") << '\n';
    cout << Solution::isCircularSentence("a b c d e a") << '\n';
    cout << Solution::isCircularSentence("leetcode Exercises sound delightful")
         << '\n';
    cout << Solution::isCircularSentence("Leetcode exercises sound delightful")
         << '\n';
    cout << Solution::isCircularSentence("MuFoevIXCZzrpXeRmTssj lYSW U jM")
         << '\n';
    cout << Solution::isCircularSentence(
                "IuTiUtGGsNydmacGduehPPGksKQyT TmOraUbCcQdnZUCpGCYtGp p pG "
                "GCcRvZDRawqGKOiBSLwjIDOjdhnHiisfddYoeHqxOqkUvOEyI")
         << '\n';
}
