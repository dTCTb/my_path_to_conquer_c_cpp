#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    static int maxUniqueSplit(const string &s) noexcept {
        unordered_set<string> st;
        st.reserve(s.size());
        return backtrack(s, 0, st);
    }

  private:
    static int backtrack(const string &s, int i, unordered_set<string> &st) {
        if (i == s.size())
            return 0;
        int max{};
        for (int j{i + 1}; j <= s.size(); ++j) {
            string tmpStr{s.substr(i, j - i)};
            // cout << tmpStr << '\n';
            // cin.ignore();
            if (st.count(tmpStr) == 0) {
                st.insert(tmpStr);
                max = std::max(max, 1 + backtrack(s, j, st));
                st.erase(tmpStr);
            }
            /* 近㗎喇，但我就係諗唔到點寫。 */
            // if (st.count(tmpStr) != 0) {
            //     return;
            // } else
            //     st.insert(tmpStr);
            // max = st.size() > max ? st.size() : max;
            // backtrack(s, i + 1, st, max);
            // if (st.count(tmpStr) != 0) {
            //     st.erase(tmpStr);
            // }
        }
        return max;
    }
};

int main() {
    cout << Solution::maxUniqueSplit("ababccc") << '\n';         // 5
    cout << Solution::maxUniqueSplit("aba") << '\n';             // 2
    cout << Solution::maxUniqueSplit("aa") << '\n';              // 1
    cout << Solution::maxUniqueSplit("wwwzfvedwfvhsww") << '\n'; // 11
    // www z f v e d w fv h s ww
}
