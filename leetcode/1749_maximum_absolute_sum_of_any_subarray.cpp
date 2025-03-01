#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static int maxAbsoluteSum(const vector<int> &nums) noexcept {
        const int ans = mySolve(nums);
        cout << "ans: " << ans << '\n';
        return ans;
    }
    static int mySolve(const vector<int> &nums) noexcept {
        int minSum{}, maxSum{};
        for (int i{}, sum{}; i < nums.size(); ++i) {
            sum += nums[i];
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
        }
        return maxSum - minSum;
    }
};

int main() {
    Solution::maxAbsoluteSum({1, -3, 2, 3, -4});     // 5
    Solution::maxAbsoluteSum({2, -5, 1, -4, 3, -2}); // 8
}
