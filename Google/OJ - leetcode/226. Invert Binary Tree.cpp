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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode *p = root->left, *q = root->right;
        root->left = q;
        root->right = p;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
