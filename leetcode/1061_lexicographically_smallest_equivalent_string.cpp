#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// parker
// morris
//
// parser
//
// p = m 0
// a = o 1
// r = r 2
// k = r 2
// e = i 3
// r = s 2
//
// mp
// ao
// ei
// krs
//
// makkek
class Solution {
  public:
    // 止步於95/116 testcase
    static string smallestEquivalentString(const string &s1, const string &s2,
                                           const string &baseStr) noexcept {
        string ans{baseStr};

        int map[26]{}, c{1};
        unsigned long strLen{s1.length()};

        for (unsigned long i{}; i < strLen; ++i) {
            int c1 = s1[i] - 'a', c2 = s2[i] - 'a';
            if (map[c1] == 0 && map[c2] == 0) {
                map[c1] = map[c2] = c++;
            } else if (map[c1] == 0 && map[c2] != 0) {
                map[c1] = map[c2];
            } else if (map[c1] != 0 && map[c2] == 0) {
                map[c2] = map[c1];
            } else {
                if (map[c2] < map[c1])
                    map[c1] = map[c2];
                else
                    map[c2] = map[c1];
            }
        }

        vector<int> tb(c + 1);

        for (int i{}; i < 26; ++i) {
            if (map[i] != 0 && tb[map[i]] == 0)
                tb[map[i]] = i + 'a';
        }

        for (int i{}; i < 26; ++i) {
            cout << char(i + 'a') << ' ';
        }
        cout.put('\n');
        for (int i{}; i < 26; ++i) {
            cout << map[i] << ' ';
        }
        cout.put('\n');
        for (int i{}; i < c; ++i) {
            cout << i << ' ';
            cout << (char)tb[i] << '\n';
        }
        cout.put('\n');

        for (int i{}; i < ans.length(); ++i) {
            if (map[baseStr[i] - 'a'] != 0)
                ans[i] = tb[map[baseStr[i] - 'a']];
        }

        cout << "ans: " << ans << '\n';

        return ans;
    }
};

int main() {
    Solution::smallestEquivalentString("parker", "morris", "parser");
    Solution::smallestEquivalentString("leetcode", "programs", "sourcecode");
    //
}
