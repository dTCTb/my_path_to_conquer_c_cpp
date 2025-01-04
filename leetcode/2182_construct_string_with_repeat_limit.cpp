#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class Solution {
  public:
    static string repeatLimitedString(const string &s,
                                      int repeatLimit) noexcept {
        return editorial_solution(s, repeatLimit);
    }

    static string editorial_solution(const string &s,
                                     int repeatLimit) noexcept {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for (auto &[ch, count] : freq) {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty()) {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(ch);
            }
        }

        return result;
    }

    static string mySolution_fail(const string &s, int repeatLimit) noexcept {
        stringstream ss;
        // array<int, 26> a;
        map<char, int, greater<char>> a;

        for (char e : s)
            ++a[e];

        string tmp;

        for_each(
            a.begin(), a.end(),
            [&ss, &tmp](const map<char, int, greater<char>>::value_type &p) {
                cout << (char)p.first << ": " << p.second << '\n';
                tmp.push_back(p.first);
            });

        while (!a.empty()) {
            for (auto it{a.begin()}; it != a.end(); ++it) {
                if (it == --a.end() && it->second > 0) {
                    ss << it->first;
                    --(it->second);
                    break;
                }
                int limit{repeatLimit};
                while (limit--) {
                    ss << it->first;
                    if (--(it->second) == 0)
                        break;
                }
            }
            for (char e : tmp)
                if (a[e] == 0)
                    a.erase(e);
        }

        string ans;
        ss >> ans;
        cout << ans << '\n';
        return ans;
    }
};

int main() {
    Solution::repeatLimitedString("cczazcc", 3);
    Solution::repeatLimitedString("aababab", 2);
}
