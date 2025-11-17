#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vInt;

class Solution {
  public:
    static bool kLengthApart(const vInt &nums, int k) noexcept {
        vInt pos{};
        pos.reserve(nums.size());
        for (unsigned i{}; i < nums.size(); ++i)
            if (nums[i])
                pos.push_back(i);
        if (pos.empty())
            return true;
        for (unsigned i{}; i < pos.size() - 1; ++i)
            if (pos[i + 1] - pos[i] - 1 < k)
                return false;
        return true;
    }
};

int main() {
    Solution s = Solution{};
    cout << s.kLengthApart(vInt{1, 0, 0, 0, 1, 0, 0, 1}, 2) << '\n'; // true
    cout << s.kLengthApart(vInt{1, 0, 0, 1, 0, 1}, 2) << '\n';       // false
    cout << s.kLengthApart(vInt{1, 0, 0, 0, 0, 0}, 2) << '\n';       // true
}
