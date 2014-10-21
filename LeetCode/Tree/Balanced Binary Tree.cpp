/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool balanced;
public:
    int height(TreeNode *node) {
        if (!node) return 0;
        int l = height(node->left) + 1;
        int r = height(node->right) + 1;
        int diff = l - r;
        if (diff > 1 || diff < -1) balanced = false;
        return max(l, r);
    }
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        balanced = true;
        height(root);
        return balanced;
    }
};
