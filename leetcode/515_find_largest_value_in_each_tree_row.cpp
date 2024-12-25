#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<int> largestValues(TreeNode *root) noexcept {
        if (!root)
            return vector<int>{};

        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int level_size{(int)q.size()};
            int max{INT_MIN};
            // cout << level_size << '\n';
            while (level_size-- != 0) {
                TreeNode *cur{q.front()};
                q.pop();

                max = cur->val > max ? cur->val : max;

                if (cur->left)
                    q.push(cur->left);

                if (cur->right)
                    q.push(cur->right);
            }
            ans.push_back(max);
        }

        return ans;
    }
};
