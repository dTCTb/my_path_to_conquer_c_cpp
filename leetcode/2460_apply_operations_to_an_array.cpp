#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static vector<int> applyOperations(const vector<int> &nums) noexcept {
        vector<int> ans{nums};
        applyOperations(ans);
        return ans;
    }

    static vector<int> applyOperations(vector<int> &nums) noexcept {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int i{1}; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i - 1]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        for (const int v : ans)
            if (v)
                ans.push_back(v);

        while (ans.size() != nums.size())
            ans.push_back(0);

        return ans;
    }
};

int main() {
    Solution::applyOperations({1, 2, 2, 1, 1, 0}); // {1,4,2,0,0,0}
    Solution::applyOperations({0, 1});             // {1,0}
}
