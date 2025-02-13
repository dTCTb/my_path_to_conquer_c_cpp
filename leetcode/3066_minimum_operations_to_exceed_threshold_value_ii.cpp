#include "./lc_tools.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<size_t> vULong; // constraints 1 <= nums[i] <= 10^9, so
                                    // unsigned long a.k.a size_t will be used
typedef std::priority_queue<size_t, vULong, greater<size_t>> pqULong;
class Solution {
  public:
    static int minOperations(const vInt &nums, const int k) noexcept {
        cout << "nums: " << nums << " | k: " << k << '\n';
        int ans = mySolve1(nums, k);
        cout << "ans: " << ans << '\n';
        return ans;
    }

    /* 83ms 91.37mb */
    static int mySolve1(const vInt &nums, const int k) noexcept {
        pqULong q{nums.cbegin(), nums.cend()};
        int ans{};

        while (q.top() < k) { /* guarantee answer always exists
            so ignoring to break the loop when q.empty() is true */
            const size_t st{q.top()};
            q.pop();
            const size_t nd{q.top()};
            q.pop();
            q.push(st * 2 + nd);
            ++ans;
        }

        return ans;
    }

    /* 104ms, 91.6mb 原來用lambda 會慢好多 */
    static int mySolve2(const vInt &nums, const int k) noexcept {
        pqULong q{nums.cbegin(), nums.cend()};
        int ans{};

        function<pair<size_t, size_t>(void)> pop = [&q]() {
            const size_t st{q.top()};
            q.pop();
            const size_t nd{q.top()};
            q.pop();
            return make_pair(st, nd);
        };

        function<void(void)> ops = [&q, &ans, &pop]() {
            const auto [st, nd] = pop();
            q.push(st * 2 + nd);
            ++ans;
        };

        while (q.top() < k)
            ops();

        return ans;
    }
};

int main() {
    Solution::minOperations({2, 11, 10, 1, 3}, 10); // 2
    Solution::minOperations({1, 1, 2, 4, 9}, 20);   // 4
}
