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
    int sum;
    int ts;
public:
    void f(TreeNode *node) {
        ts = 10 * ts + node->val;
        if (node->left == NULL && node->right == NULL) sum += ts;
        if (node->left != NULL) f(node->left);
        if (node->right != NULL) f(node->right);
        ts = (ts - node->val) / 10;
    }
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        sum = 0; ts = 0;
        f(root);
        return sum;
    }
};
