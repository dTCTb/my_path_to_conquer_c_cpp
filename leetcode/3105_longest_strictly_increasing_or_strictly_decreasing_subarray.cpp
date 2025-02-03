#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int longestMonotonicSubarray(const vInt &nums) noexcept {
        if (nums.size() == 1)
            return 1;

        int ans{1};

        for (int i{}, j{1}; i < nums.size() - 1;) {
            if (nums[j - 1] == nums[j]) {
                ++i, ++j;
                continue;
            }
            if (nums[i] > nums[j])
                while (j < nums.size() && nums[j - 1] > nums[j])
                    ++j;
            else
                while (j < nums.size() && nums[j - 1] < nums[j])
                    ++j;
            ans = max(j - i, ans);
            i = j - 1;
        }

        cout << ans << '\n';
        return ans;
    }
};

int main() {
    auto test = bind(Solution::longestMonotonicSubarray, placeholders::_1);
    test(vInt{1});                                  // 1
    test(vInt{5, 8, 10, 9, 8});                     // 3
    test(vInt{24, 47, 24, 23, 14, 6, 9, 2, 3, 19}); // 5
    test(vInt{21, 32, 1, 39, 40, 24, 6,  21, 24, 33,
              25, 33, 6, 50, 34, 14, 24, 12, 2,  1}); // 4
    test(vInt{50, 32, 13, 18, 32, 16, 12, 4,  18, 36, 5,  6,  12,
              14, 37, 45, 36, 13, 14, 48, 8,  45, 33, 39, 40, 8,
              45, 4,  36, 13, 44, 32, 15, 35, 1,  50, 14, 41, 43,
              17, 13, 11, 44, 3,  25, 14, 10, 7,  2,  44}); // 6
    test(vInt{50, 22, 16, 14, 47, 36, 36, 33, 23, 5,  50, 19, 17,
              15, 19, 27, 33, 6,  12, 32, 25, 42, 44, 30, 30, 42,
              35, 19, 28, 2,  36, 33, 15, 5,  24, 19, 17, 42, 33,
              46, 40, 39, 5,  2,  37, 36, 41, 7,  27, 28}); // 5
    test(vInt{49, 50, 50, 49, 48, 47, 50, 46, 45, 44, 43, 42, 41,
              40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28,
              27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15,
              14, 13, 12, 11, 10, 9,  8,  7,  6,  5}); // 43
    test(vInt{50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
              50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
              50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
              50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}); // 1
}
