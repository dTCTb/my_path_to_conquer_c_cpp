#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int maxChunksToSorted(const vInt &arr) noexcept {
        int ans{};
        for (int i{}; i < arr.size(); ++i) {
            int j{i}, max{};
            bool reach{false};
            while (j < arr.size() && ((arr[j] != i && !reach) || j < max)) {
                if (!reach)
                    reach = arr[j] == i;
                max = arr[j] > max ? arr[j] : max;
                ++j;
            }
            ++ans;
            i = j;
        }
        cout << ans << '\n';
        return ans;
    }
};

int main() {
    auto test = bind(Solution::maxChunksToSorted, placeholders::_1);
    test(vInt{4, 3, 2, 1, 0});                      // 1
    test(vInt{1, 0, 2, 3, 4});                      // 4
    test(vInt{1, 4, 3, 6, 0, 7, 8, 2, 5});          // 1
    test(vInt{0, 2, 4, 3, 1, 9, 5, 6, 7, 8});       // 3
    /* 46 */ test(vInt{1, 4, 0, 2, 3, 5});          // 2
    /* 43 */ test(vInt{2, 0, 1, 3});                // 2
    /* 50 */ test(vInt{1, 5, 3, 0, 2, 8, 7, 6, 4}); // 1
}
