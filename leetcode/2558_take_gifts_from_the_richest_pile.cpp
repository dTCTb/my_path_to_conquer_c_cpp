#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;
typedef std::vector<int> vInt;
class Solution {
  public:
    static ll pickGifts(vInt &gifts, int k) {
        ll ans{accumulate(gifts.cbegin(), gifts.cend(), 0LL)};
        priority_queue<int, vInt, less<int>> pq{gifts.begin(), gifts.end()};
        for (ll i{}, tmp{}; i < k; ++i)
            ans -= pq.top() - (tmp = sqrt(pq.top())), pq.pop(), pq.push(tmp);
        cout << "ans: " << ans << '\n';
        return ans;
    }
};

int main() {
    vInt e1{25, 64, 9, 4, 100};
    Solution::pickGifts(e1, 4);

    vInt e2{1, 1, 1, 1};
    Solution::pickGifts(e2, 4);
}
