#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef std::stack<char, vector<char>> vCharSk;
class Solution {
  public:
    static string smallestNumber(const string pattern) noexcept {
        const string ans{mySolve(pattern)};
        cout << "ans: " << ans << '\n';
        return ans;
    }

    /* O(n) 0ms 7.83mb */
    static string mySolve(const string pattern) noexcept {
        string ans = "1";
        vCharSk sk({'9', '8', '7', '6', '5', '4', '3', '2'}), tmp;

        for (const char dir : pattern) {
            if (dir == 'D') {
                while (sk.top() - ans.back() != 1) {
                    tmp.push(ans.back());
                    ans.pop_back();
                }
                tmp.push(ans.back());
                ans.pop_back();
            }

            ans.push_back(sk.top());
            sk.pop();

            while (!tmp.empty()) {
                ans.push_back(tmp.top());
                tmp.pop();
            }
        }
        return ans;
    }
};

int main() {
    Solution::smallestNumber("IIIDIDDD");
    Solution::smallestNumber("DDD");
    Solution::smallestNumber("DIDDI");
}
