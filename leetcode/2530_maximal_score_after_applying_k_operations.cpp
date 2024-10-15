#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static long long maxKelements(vector<int> &&nums, int k) noexcept {
        long long score{};
        priority_queue<int, vector<int>, less<int>> l{nums.begin(), nums.end()};

        while (k--) {
            int tmp{l.top()};
            l.pop();
            score += tmp;
            l.push(static_cast<int>(ceil(tmp / 3.0)));
        }

        // while (!l.empty()) {
        //   cout << l.top() << ' ';
        //   l.pop();
        // }
        // cout.put('\n');

        return score;
    }
};

int main() {
    cout << Solution::maxKelements({10, 10, 10, 10, 10}, 5) << '\n'; // 50
    cout << Solution::maxKelements({1, 10, 3, 3, 3}, 3) << '\n';     // 17
}
