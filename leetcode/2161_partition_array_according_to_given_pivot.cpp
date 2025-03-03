#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    /* 3ms 131.35mb */
    static vInt pivotArray(const vInt &nums, const int pivot) noexcept {
        int c{};
        vInt l, r;
        l.reserve(nums.size());

        for (const int v : nums)
            if (v < pivot)
                l.push_back(v);
            else if (v > pivot)
                r.push_back(v);
            else
                ++c;

        while (c--)
            l.push_back(pivot);

        l.insert(l.end(), r.begin(), r.end());

        return l;
    }
};

int main() {
    Solution::pivotArray({9, 12, 5, 10, 14, 3, 10}, 10);
    Solution::pivotArray({-3, 4, 3, 2}, 2);
}
