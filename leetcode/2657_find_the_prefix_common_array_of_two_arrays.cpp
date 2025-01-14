#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static vInt findThePrefixCommonArray(const vInt &A,
                                         const vInt &B) noexcept {
        int count{};
        bool record[51]{};
        vInt ans{};
        ans.reserve(A.size());
        for (size_t i{}; i < A.size(); ++i) {
            if (record[A[i]])
                ++count;
            if (record[B[i]])
                ++count;
            if (A[i] == B[i])
                ++count;
            record[A[i]] = true;
            record[B[i]] = true;
            ans.push_back(count);
        }
        for (const int v : ans)
            cout << v << ", ";
        cout << "\b\b \n";
        return ans;
    }
};

int main() {
    using namespace placeholders;
    auto test = bind(Solution::findThePrefixCommonArray, _1, _2);

    test(vInt{1, 3, 2, 4}, vInt{3, 1, 2, 4}); // {0,2,3,4}
    test(vInt{2, 3, 1}, vInt{3, 1, 2});       // {0,1,3}
}
