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
    int height(TreeNode *node) {
        if (!node) return 0;
        int left = height(node->left);
        int right = height(node->right);
        if (left == -1 || right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (height(root) == -1) return false;
        else return true;
    }
};
