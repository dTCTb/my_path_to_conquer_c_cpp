#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int numEquivDominoPairs(const vector<vector<int>> &dominoes) {
        vector<int> num(100, 0);
        int ans{};
        for (const auto &dominoe : dominoes) {
            int a = dominoe[0] < dominoe[1] ? dominoe[0] * 10 + dominoe[1]
                                            : dominoe[0] + dominoe[1] * 10;
            ans += num[a];
            ++num[a];
        }
        return ans;
    }
};

int main() {
    Solution s{};
    s.numEquivDominoPairs(
        vector<vector<int>>{vector<int>{1, 2}, {2, 1}, {3, 4}, {5, 6}});
}
