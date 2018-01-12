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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        if (root->left) { // check if we could finish search on left child and add it to sum
            if (root->left->left == nullptr && root->left->right == nullptr) {
                ans += root->left->val;
            } else {
                ans += sumOfLeftLeaves(root->left);
            }
        }
        ans += sumOfLeftLeaves(root->right);
        return ans;
    }
};
