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
    int h = -1;
    void dfs(TreeNode *node, int height) {
        if (!node) return;
        if (height > h) {
            h = height;
            ans = node->val;
        }
        dfs(node->left, height + 1);
        dfs(node->right, height + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        // traverse the tree pre-order 
        dfs(root, 0);
        return ans;
    }
};
