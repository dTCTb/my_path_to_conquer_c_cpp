#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static vector<int> decrypt(const vector<int> &code, int k) noexcept {
        if (k == 0)
            return vector<int>(code.size(), 0);

        int codeSize{static_cast<int>(code.size())};
        vector<int> ans{};
        ans.reserve(code.size());

        auto next = [codeSize](int i) -> int {
            if (i + 1 == codeSize)
                return 0;
            else
                return i + 1;
        };

        int i{1}, j{1};
        if (k < 0) {
            i = (k + codeSize) % codeSize;
            j = i;
            k = abs(k);
        }

        for (int s{}, c{}; ans.size() < code.size(); j = next(j)) {
            ++c;
            s += code[j];
            if (c == k) {
                ans.push_back(s);
            }
            if (c > k) {
                s -= code[i];
                i = next(i);
                ans.push_back(s);
            }
        }

        for (int &e : ans)
            cout << e << ',';
        cout.put('\n');

        return ans;
    }
};

int main() {
    Solution::decrypt({5, 7, 1, 4}, 3);
    Solution::decrypt({1, 2, 3, 4}, 0);
    Solution::decrypt({2, 4, 9, 3}, -2);
}
