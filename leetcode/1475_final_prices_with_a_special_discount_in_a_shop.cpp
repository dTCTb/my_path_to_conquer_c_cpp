#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::stack<int, vInt> skInt;
class Solution {
  public:
    static vInt finalPrices(vInt &prices) noexcept {
        skInt tran, sk;
        for (int i{(int)prices.size() - 1}; i >= 0; --i)
            sk.push(prices[i]);

        int idx{};
        while (!sk.empty()) {
            int tmp = sk.top();
            sk.pop();

            while (!sk.empty() && sk.top() > tmp)
                popping(sk, tran);

            prices[idx++] = !sk.empty() ? tmp - sk.top() : tmp;

            while (!tran.empty())
                popping(tran, sk);
        }
        return prices;
    }

    static inline void popping(skInt &from, skInt &to) noexcept {
        to.push(from.top());
        from.pop();
    }
};

int main() {
    vInt e1{8, 4, 6, 2, 3};
    Solution::finalPrices(e1);
}
