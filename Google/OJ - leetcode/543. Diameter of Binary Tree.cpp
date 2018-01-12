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
    int f(TreeNode *node) {
        /* find max path from this node to leaf */
        if (!node) return 0;
        int left = f(node->left);
        int right = f(node->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return max(ans - 1, 0); // a little hack
    }
};
