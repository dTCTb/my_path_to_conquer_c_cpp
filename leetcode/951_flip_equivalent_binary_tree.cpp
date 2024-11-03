// clang-format off
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val{x}, left{left}, right{right} {}
};

class Solution {
  public:
    typedef const TreeNode *const TreeNode_cp;
    typedef unordered_set<string> Collection;

    Solution() {
        std::cin.tie(0);
        std::cout.tie(0);
        std::ios::sync_with_stdio(false);
    }

    bool flipEquiv(TreeNode_cp root1, TreeNode_cp root2) const noexcept {
        Collection collection; collection.reserve(100);
        string     record    ; record.reserve(100);

        dfs(root1, record, collection);
        dfs(root2, record, collection);

        return collection.empty();
    }

  private:
    void dfs(TreeNode_cp root, string &record, Collection &collection) const noexcept {
        if (!root) {
            if (collection.contains/*C++20 feature*/(record)) collection.erase(record);
            else                                              collection.insert(record);
            return;
        }

        record.push_back(root->val);

        dfs(root->left,  record, collection);
        dfs(root->right, record, collection);

        record.pop_back();
    }
};

int main() {
    ;
    ;
}
