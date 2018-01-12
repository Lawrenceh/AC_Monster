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
    int maxPathDown(TreeNode *root, int &sum) {
        if (!root) return 0;
        int left = max(0, maxPathDown(root->left, sum));
        int right = max(0, maxPathDown(root->right, sum));
        sum = max(sum, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxPathDown(root, sum);
        return sum;
    }
};
