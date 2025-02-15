/* 10 * 10 = 100  10 + 0
36 * 36 = 1296 1 + 29 + 6

1296 / 1000 | 1 296
296  /  100 | 2 96
96   /   10 | 9
    96 / 1 | 96
6    /    1 | 6 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int punishmentNumber(int n) {
        int ans{};
        for (size_t i{}; i <= n; ++i) {
            auto it = find(data.cbegin(), data.cend(), i);

            if (it != data.cend()) {
                ans += *it * *it;
            } else if (bt(i, i * i)) {
                data.push_back(i);
                ans += i * i;
            }
        }
        return ans;
    }

  private:
    static vector<int> data;
    int bt(const int tar, const int cur) {
        if (tar < 0 || cur < tar)
            return false;
        if (tar == cur)
            return true;
        return bt(tar - cur % 10, cur / 10) || bt(tar - cur % 100, cur / 100) ||
               bt(tar - cur % 1000, cur / 1000);
    }
};

vector<int> Solution::data{};

int main() {
    Solution s{};
    cout << s.punishmentNumber(8) << '\n';
    cout << s.punishmentNumber(10) << '\n';
    cout << s.punishmentNumber(37) << '\n';
}
