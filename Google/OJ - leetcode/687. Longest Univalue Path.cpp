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
    int ans = 0;
    int dfs(TreeNode *node) {
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        int retl = 0, retr = 0;
        if (node->left && node->left->val == node->val) retl = l + 1;
        else retl = 0;
        if (node->right && node->right->val == node->val) retr = r + 1;
        else retr = 0;
        ans = max(ans, retl + retr);
        return max(retl, retr);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
