#include "./lc_tools.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::unordered_map<size_t,
                           priority_queue<size_t, vector<size_t>, less<size_t>>>
    Map;
class Solution {
  public:
    static int maximumSum(const vInt &nums) noexcept {
        cout << nums << '\n';
        int ans = mySolve(nums);
        cout << "ans: " << ans << '\n';
        return ans;
    }

    /* 20ms 78.36mb one-take pass! */
    static int mySolve(const vInt &nums) noexcept {
        Map map{};
        size_t ans{};

        for (const int num : nums)
            map[digitSum(num)].push(num);

        // printMap(map);
        for (auto &[digitSum, member] : map) {
            if (member.size() < 2)
                continue;
            size_t tmp{member.top()};
            member.pop();
            ans = max(ans, tmp + member.top());
        }
        return ans == 0 ? -1 : ans;
    }

  private:
    static int digitSum(size_t num) noexcept {
        int sum{};
        while (num)
            sum += num % 10, num /= 10;
        return sum;
    }

    static void printMap(Map map) noexcept {
        for (auto &[digitSum, member] : map) {
            cout << digitSum << ": ";
            while (!member.empty()) {
                cout << member.top() << ", ";
                member.pop();
            }
            cout << "\b\b \n";
        }
    }
};

int main() {
    Solution::maximumSum({18, 43, 36, 13, 7}); // 54
    Solution::maximumSum({10, 12, 19, 14});    // -1
}
