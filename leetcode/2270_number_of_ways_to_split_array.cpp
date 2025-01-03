#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int waysToSplitArray(const vInt &nums) noexcept {
        int ans{};
        long acc{accumulate(nums.cbegin(), nums.cend(), 0L)};
        // cout << "accumulate: " << acc << "\n";

        for (long i{}, l{0}; i < nums.size() - 1; ++i)
            if ((l += nums[i]) >= (acc -= nums[i]))
                ++ans;
        // cout << "l: " << l << " acc: " << acc << '\n';

        // cout << "ans: " << ans << '\n';
        return ans;
    }
};

int main() {
    auto test = bind(Solution::waysToSplitArray, placeholders::_1);
    test(vInt{10, 4, -8, 7});               // 2
    test(vInt{2, 3, 1, 0});                 // 2
    test(vInt{0, 0});                       // 1
    test(vInt{9, 9, 9});                    // 1
    test(vInt{6, -1, 9});                   // 0
    test(vInt{10, 4, 5, 6, 1, -2, -3, -4}); // 7
    test(vInt{0,   -1,  -2,  -3,  -4,  -5,  -6,  -7,  -8,  -9,  -10, -11, -12,
              -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23, -24, -25,
              -26, -27, -28, -29, -30, -31, -32, -33, -34, -35, -36, -37, -38,
              -39, -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, -50, -51,
              -52, -53, -54, -55, -56, -57, -58, -59, -60, -61, -62, -63, -64,
              -65, -66, -67, -68, -69, -70, -71, -72, -73, -74, -75, -76, -77,
              -78, -79, -80, -81, -82, -83, -84, -85, -86, -87, -88, -89, -90,
              -91, -92, -93, -94, -95, -96, -97, -98, -99, -100}); // 71
}
