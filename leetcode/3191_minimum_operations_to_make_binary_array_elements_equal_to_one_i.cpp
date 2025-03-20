#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int minOperations(const vInt &nums) noexcept {
        vInt n{nums};
        return mySolve(n);
    }

    static int mySolve(vInt &n) noexcept {
        int ans{};
        for (int i{}; i <= n.size() - 3; ++i) {
            while (i <= n.size() - 3 && n[i] != 0)
                ++i;

            if (i > n.size() - 3)
                break;

            n[i] = 1;
            n[i + 1] ^= 1;
            n[i + 2] ^= 1;
            ++ans;
        }
        if (n[n.size() - 3] + n[n.size() - 2] + n[n.size() - 1] != 3)
            ans = -1;
#ifdef ANSWER
        cout << "ans: " << ans << '\n';
#endif
        return ans;
    }
};

int main() {
    Solution::minOperations({0, 1, 1, 1, 0, 0});          // 3
    Solution::minOperations({0, 0, 1, 0, 0, 1, 0});       // -1
    Solution::minOperations({1, 0, 0, 1, 0, 1, 1, 0, 0}); // -1
}
