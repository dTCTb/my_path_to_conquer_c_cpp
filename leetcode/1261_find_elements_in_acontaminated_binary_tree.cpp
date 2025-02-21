#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val{x}, left{left}, right{right} {}
};

class FindElements {
  public:
    FindElements(TreeNode *root) {
        ++tmp[root->val = 0];
        dfs(root);
        // cout.put('\n');
    }

    bool find(int target) { return tmp[target]; }

  private:
    map<int, int> tmp{};

    void dfs(TreeNode *const cur) {
        // cout << cur->val << ' ';
        if (cur->left) {
            ++tmp[cur->left->val = 2 * cur->val + 1];
            dfs(cur->left);
        }
        if (cur->right) {
            ++tmp[cur->right->val = 2 * cur->val + 2];
            dfs(cur->right);
        }
    }
};
