#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::pair<int, int> pIntInt;
typedef std::priority_queue<pIntInt, deque<pIntInt>, std::greater<pIntInt>> PQ;
class Solution {
  public:
    static vInt getFinalState(vInt &nums, int k, int multiplier) noexcept {
        PQ pq;

        for (int i{}; i < nums.size(); ++i)
            pq.push({nums[i], i});

        while (k-- > 0) {
            pIntInt tmp = pq.top();
            tmp.first *= multiplier;
            pq.pop();
            pq.push({tmp.first, tmp.second});
            nums[tmp.second] = tmp.first;
        }

        return nums;
    }
    static void print(PQ pq) noexcept {
        while (!pq.empty()) {
            cout << pq.top().first << ", " << pq.top().second << '\n';
            pq.pop();
        }
        cout << "- -- - -- - -- -\n";
    }
};

int main() {
    vInt e1{2, 1, 3, 5, 6};
    vInt e2{1, 2};
    Solution::getFinalState(e1, 5, 2);
    Solution::getFinalState(e2, 3, 4);
}
