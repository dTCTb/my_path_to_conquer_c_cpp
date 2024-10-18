#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Solution {
  public:
    static string longestDiversetString(int a, int b, int c) noexcept {
        array<pair<int, char>, 3> order{{{a, 'a'}, {b, 'b'}, {c, 'c'}}};
        sort(order.begin(), order.end(),
             [](auto l, auto r) { return l.first > r.first; });
        string redro{};
        redro.reserve(a + b + c);

        for (size_t i{}, k{}; i < order.size(); ++i) {
            char fillThis = i == 0 ? 'a' : i == 1 ? 'b' : 'c';
            for (size_t j{}; j < order[i].first; ++j)
                redro.push_back(order[i].second);
        }

        // bool end = false;
        // cout << redro << '\n';
        // if (redro.size() > 2)
        //     for (size_t i{}, j{2}, k{redro.size() - 1}; i < redro.size() - 2;
        //          ++i, ++j) {
        //         if (j > redro.size())
        //             break;
        //         if (redro[i] == redro[j] /*&& redro[i] != redro[k]*/) {
        //             if (redro[i] != redro[k]) {
        //                 end = false;
        //                 swap(redro, j, k);
        //             } else {
        //                 if (end)
        //                     break;
        //                 else
        //                     k = redro.size() - 1;
        //                 end = true;
        //                 continue;
        //             }
        //
        //             i = j;
        //             j += 2;
        //             --k;
        //             // k = k > order[0].first ? --k : redro.size() - 1;
        //         }
        //     }

        cout << redro << '\n';
        int down{order[1].first | order[2].first};
        for (int i{}, j{}, k{(int)redro.size() - 1}; i < redro.size(); ++i) {
            if (i - 1 >= 0) {
                j += redro[i - 1] == redro[i] ? 1 : 0;
            }
            if (down == 0) {
                down = i + 2;
            }
            if (j == 2) {
                int tmp{k};
                while (redro[i] == redro[tmp]) {
                    if (tmp < order[1].first + order[2].first)
                        break;
                    --tmp;
                }
                swap(redro, i, tmp);
                --down;
                j = 0;
            }
        }

        cout << redro.substr(down) << '\n';
        return redro;
    }

  private:
    static void swap(string &s, size_t l, size_t r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
    }
};

int main() {
    Solution::longestDiversetString(1, 1, 7);
    Solution::longestDiversetString(7, 1, 0);
    Solution::longestDiversetString(0, 9, 12);
    // Solution::longestDiversetString(100, 100, 100);
    // Solution::longestDiversetString(0, 0, 7);
    // // Solution::longestDiversetString(58, 50, 87);
    // Solution::longestDiversetString(65, 56, 95);
    // Solution::longestDiversetString(67, 53, 99);
    // Solution::longestDiversetString(5, 4, 3);
    // Solution::longestDiversetString(3, 40, 7);
}
