#include <iostream>
#include <numeric>

using namespace std;

// totally fail, so fucking complicated even others say it is so easy
// maybe I am not good on today 14-11-2024
class Solution {
  public:
    static int minimizedMaximum(int n, vector<int> &quantities) noexcept {
        vector<int> &q{quantities};
        const int max{*max_element(q.cbegin(), q.cend())};
        unsigned long total{accumulate(q.cbegin(), q.cend(), 0UL)};

        function<bool(int)> canDistribute = [&q, &n,
                                             total](const int a) -> bool {
            int tmp{};
            unsigned long t{total};
            for (const int &e : q) {
                tmp += e / a;
                if (e % a != 0)
                    ++tmp;
                if (tmp > n)
                    return false;
                t -= e;
            }
            return t == 0 ? true : false;
        };

        int left{1};
        int answer{max};
        while (left < answer) {
            int middle = (answer + left) / 2;
            if (canDistribute(middle))
                answer = middle;
            else
                left = middle + 1;
        }

        return answer;
    }
};

int main() {
    ;
    ;
}
