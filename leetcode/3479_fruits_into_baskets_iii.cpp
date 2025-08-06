#include <iostream>
// #define DEBUG
// or make 3479 FLAG=-DDEBUG

using namespace std;
typedef vector<int> vInt;
#define LLeaf(idx) ((2 * idx) + 1)
#define RLeaf(idx) ((2 * idx) + 2)
#define TREE_SIZE (1 << 18)

int tree[TREE_SIZE]{};

struct segTree {
    segTree(const vInt &data) { build(data, 0, 0, data.size() - 1); }

    void build(const vInt &data, const int idx, const int l, const int r) {
        if (l == r) {
            tree[idx] = data[l];
        } else {
            const int m = (l + r) / 2;
            build(data, LLeaf(idx), l, m);
            build(data, RLeaf(idx), m + 1, r);
            tree[idx] = std::max(tree[LLeaf(idx)], tree[RLeaf(idx)]);
        }
    }

    int query(const int amount, const int idx, const int l, const int r) {
        if (tree[idx] < amount)
            return -1;
        else if (l == r) {
            tree[idx] = -1;
            return l;
        } else {
            const int m = (l + r) / 2;
            int ret{};

            if (tree[LLeaf(idx)] >= amount)
                ret = query(amount, LLeaf(idx), l, m);
            else
                ret = query(amount, RLeaf(idx), m + 1, r);

            tree[idx] = max(tree[LLeaf(idx)], tree[RLeaf(idx)]);
            return ret;
        }
    }

#ifdef DEBUG
    void print(const vInt &data) const {
        unsigned long height{1}, c{data.size()};
        while (c) {
            ++height;
            c >>= 1;
        }
        for (int i{}, h{1}; i < TREE_SIZE - 1 && height; --height, h <<= 1) {
            for (int j{}; j < h; ++i, ++j)
                cout << tree[i] << ' ';
            cout.put('\n');
        }
    }
#endif

    ~segTree() { std::fill(begin(tree), end(tree), 0); }
};

class Solution {
  public:
    static int numOfUnplacedFruits(const vInt &fruits, const vInt &baskets) {
        segTree seg_tree = segTree(baskets);
        int ans{};
#ifdef DEBUG
        seg_tree.print(baskets);
#endif
        for (const int fruit : fruits)
            if (seg_tree.query(fruit, 0, 0, fruits.size() - 1) == -1)
                ++ans;
#ifdef DEBUG
        cout << "ans: " << ans << '\n';
#endif
        return ans;
    }
};

int main() {
    Solution::numOfUnplacedFruits({4, 2, 5}, {3, 5, 4}); // 1
    Solution::numOfUnplacedFruits({3, 6, 1}, {6, 4, 7}); // 0
    Solution::numOfUnplacedFruits({4, 2, 5, 9, 1, 2, 5},
                                  {3, 5, 4, 7, 3, 2, 3}); // 2
    //        7
    //    7       3
    //  5   7   3   3
    // 3 5 4 7 3 2 0 0
}
