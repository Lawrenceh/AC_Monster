/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void dfs(TreeNode *node, int curr) {
        if (node->left == nullptr && node->right == nullptr) {
            sum += curr * 10 + node->val;
        } else {
            if (node->left) dfs(node->left, curr * 10 + node->val);
            if (node->right) dfs(node->right, curr * 10 + node->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return sum;
        dfs(root, 0);
        return sum;
    }
};
