#include <cmath>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

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
    static TreeNode *reverseOddLevels(TreeNode *root) noexcept {
        int level{}, count{};
        deque<TreeNode *> dq;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur{q.front()};

            // when reach the starting node at a new level
            if (pow(2, level) * 2 - 1 == count) {
                ++level;
                // and reverse previously nodes' value
                while (dq.size() > 1) {
                    swap(dq.front()->val, dq.back()->val);
                    dq.pop_back();
                    dq.pop_front();
                }
            }

            cout << "level: " << level << " | ";
            cout << cur->val << '\n';

            if (cur->left) {
                q.push(cur->left);
                q.push(cur->right);
            }

            // push odd level node into deque pending for swapping
            if (level % 2 == 0) {
                dq.push_back(cur->left);
                dq.push_back(cur->right);
            }

            q.pop();
            ++count;
        }
        cout << "count: " << count << '\n';
        return root;
    }
};
