#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    static int numOfUnplacedFruits(const vector<int> &fruits,
                                   vector<int> &baskets) {
        int placed{};
        for (int i{}; i < fruits.size(); ++i)
            for (int j{}; j < baskets.size(); ++j) {
                if (fruits[i] <= baskets[j]) {
                    baskets[j] = 0;
                    ++placed;
                    break;
                }
            }

        return fruits.size() - placed;
    }
};

int main() {
    vector<int> t1 = {3, 5, 4};
    int t1_ans = Solution::numOfUnplacedFruits({4, 2, 5}, t1);
    if (t1_ans == 1)
        cout << "true\n";

    vector<int> t2 = {6, 4, 7};
    int t2_ans = Solution::numOfUnplacedFruits({3, 6, 1}, t2);
    if (t2_ans == 0)
        cout << "true\n";
}
