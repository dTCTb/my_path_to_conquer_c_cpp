#include "./lc_tools.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    /* O(n * k) 48ms 113mb */
    static int numberOfAlternatingGroups(const vInt &colors, int k) noexcept {
        int ans{};
        bool globalFlag{};
        vInt arr = colors;

        for (size_t i{}; i < k - 1; ++i)
            arr.push_back(colors[i]);
#if defined(LC_TOOLS) && defined(DEBUG)
        cout << arr << '\n';
#endif

        for (size_t i{}; arr.size() - i >= k; ++i) {
#ifdef DEBUG
            cout << "i: " << i << ' ';
#endif
            if (!globalFlag) {
                bool flag{false};
                for (size_t j{i}; j < i + k - 1; ++j) {
                    if (arr[j] == arr[j + 1]) {
                        i += j - i;
                        flag = true;
                        globalFlag = false;
                        break;
                    }
                }
                if (!flag) {
                    ++ans;
                    globalFlag = true;
                }
            } else {
#ifdef DEBUG
                cout << i - 1 << i + k - 1 << ' ';
#endif
                if (k % 2 == 0 ? arr[i] != arr[i + k - 1]
                               : 1 && arr[i] == arr[i + k - 1])
                    ++ans;
                else {
                    i += k - 2; // -2 coz of for-loop post expression will ++i
                    // e.g. [1,2,3,4,5] k = 3
                    //       i ^ ^ ^
                    //         | | |_k
                    //         | |_k-1
                    //         |_k-2
                    globalFlag = false;
                }
            }
#ifdef DEBUG
            cout << "ans: " << ans << "\n---\n";
#endif
        }

#ifdef ANSWER
        cout << "ans: " << ans << "\n\n";
#endif
        return ans;
    }
};

int main() {
    Solution::numberOfAlternatingGroups({0, 1, 0, 1, 0}, 3);       // 3
    Solution::numberOfAlternatingGroups({0, 1, 0, 0, 1, 0, 1}, 6); // 2
    Solution::numberOfAlternatingGroups({1, 1, 0, 1}, 4);          // 0
}
