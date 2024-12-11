#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int maximumBeauty(vInt &nums, int k) noexcept {
        sort(nums.begin(), nums.end());
        int i{}, j{}, ans{};

        while (i < nums.size()) {
            if (j < nums.size() && nums[j] - nums[i] <= k * 2) {
                ans = j - i + 1 > ans ? j - i + 1 : ans;
                ++j;
            } else {
                ++i;
                ans = j - i + 1 > ans ? j - i + 1 : ans;
            }
            // cout << "i: " << i << " j: " << j << " ans: " << ans << '\n';
        }
        // cout << ans << '\n';
        return ans;
    }
};

int main() {
    vInt e1{4, 6, 1, 2};
    cout << Solution::maximumBeauty(e1, 2) << '\n';

    vInt e2{1, 1, 1, 1};
    cout << Solution::maximumBeauty(e2, 10) << '\n';
}
