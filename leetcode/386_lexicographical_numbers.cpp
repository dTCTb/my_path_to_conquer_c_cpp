#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 錯嘅Solution
class Solution {
  public:
    vector<int> ret;
    int n;
    vector<int> lexicalOrder(int n) {
        this->n = n;

        for (size_t i{1}; i < n; ++i) {
            ret.push_back(i);
            foo(i);
            if (ret.size() == n)
                break;
        }

        for (int i : ret)
            cout << i << ' ';
        cout.put('\n');
        return ret;
    }

    void foo(int m) {
        if (m > n) {
            return;
        }
        if ((m *= 10) <= n)
            ret.push_back(m);
        foo(m);
        if (m <= n) {
            for (size_t i{1}; i <= 9 && m + i <= n; ++i) {
                ret.push_back(m + i);
            }
        }
    }
};

int main() {
    Solution s1;
    // eg1
    // n = 13
    // 1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9
    s1.lexicalOrder(13);
    // eg2
    // n = 2
    // 1, 2
    Solution s2;
    s2.lexicalOrder(101);

    // Solution s3;
    // s3.lexicalOrder(211);
}
