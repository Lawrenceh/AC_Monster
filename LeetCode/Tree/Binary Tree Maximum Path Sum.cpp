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
    int diameter;
public:
    int f(TreeNode *node) { // f(node): weighted-value height of node! (instead of diameter)
        if (!node) return 0;
        int val = node->val;
        int lval = f(node->left);
        int rval = f(node->right);
        int ret = max(max(val, val + lval), val + rval);
        int t = max(ret, val + lval + rval);
        if (t > diameter) diameter = t;
        return ret;
    }
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        diameter = -1 << 14;
        f(root);
        return diameter;
    }
};
