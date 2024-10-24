#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val{}, left{nullptr}, right{nullptr} {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val{x}, left{left}, right{right} {}
};

class Solution {
    long long maxLevel{};

  public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        long long arr[100'000]{};
        bfs(root, arr);
        sort(begin(arr), end(arr), greater<long long>());

        return maxLevel < k - 1 ? -1 : arr[k - 1];
    }

  private:
    void bfs(TreeNode *root, long long *arr) {
        static long long level{};
        if (!root)
            return;

        maxLevel = level > maxLevel ? level : maxLevel;
        arr[level] += root->val;

        ++level;
        bfs(root->left, arr);
        bfs(root->right, arr);
        --level;
    }
};
