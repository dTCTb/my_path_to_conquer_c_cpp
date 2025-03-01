#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static string getHappyString(const int n, const int k) noexcept {
        string ans;
        int count{};
        bt(ans, n, k, count);
        cout << "ans: " << ans << '\n';
        return ans;
    }

  private:
    static inline const char happy[]{'a', 'b', 'c'};
    /* 0ms 7.84mb */
    static bool bt(string &cur, const int n, const int k, int &c) {
        if (c == k)
            return true;

        if (cur.size() < n) {
            for (const char ch : happy) {
                if (!cur.empty() && cur.back() == ch)
                    continue;

                cur.push_back(ch);
                c += cur.size() == n ? 1 : 0;
                // cout << ": " << cur << " " << c << '\n';
                if (bt(cur, n, k, c))
                    return true;
            }
            if (!cur.empty())
                cur.pop_back();
        } else
            cur.pop_back();

        return false;
    }
};

// const char Solution::happy[3]{'a', 'b', 'c'};

int main() {
    Solution::getHappyString(1, 3);    // "c"
    Solution::getHappyString(3, 9);    // "cab"
    Solution::getHappyString(1, 4);    // ""
    Solution::getHappyString(5, 2);    // "ababc"
    Solution::getHappyString(4, 100);  // ""
    Solution::getHappyString(9, 99);   // "abcbabaca"
    Solution::getHappyString(1, 1);    // "a"
    Solution::getHappyString(5, 44);   // "cbacb"
    Solution::getHappyString(7, 16);   // "abacbcb"
    Solution::getHappyString(5, 33);   // "cabab"
    Solution::getHappyString(10, 100); // "abacbabacb"
}
