#include <bitset>
#include <iostream>

using namespace std;

class Solution {
  public:
    static char findKthBit(int n, int k) noexcept {
        bitset<1'048'576> bset;
        bset.set(1, false);
        return k == 1 ? '0' : recur(bset, 2, 2, k);
    }

  private:
    // pos 每次入都locate 喺新位（即係'1'）
    static char recur(bitset<1'048'576> &bset, int pos, int k,
                      const int &target) {
        bset.set(k++, true);
        size_t calPos{(size_t)k - 1};
        for (size_t i{}; i < calPos; ++i, ++k) {
            if (k == target)
                return bset[k] ? '1' : '0';
            bset.set(k, ~bset[k - pos + i]);
        }
        return recur(bset, k - 1, k, target);
    }
};

int main() {
    Solution::findKthBit(3, 1);  // 0
    Solution::findKthBit(4, 11); // 1
}
