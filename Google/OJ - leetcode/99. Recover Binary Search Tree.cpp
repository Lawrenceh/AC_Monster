/* use morris traversal for O(1) space */

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
    TreeNode *first = nullptr, *second = nullptr, *prev = new TreeNode(INT_MIN);
    void dfs(TreeNode *node) {
        if (!node) return;
        dfs(node->left);
        /* this doesn't cover two element cases such as [1, 0]
        if (prev->val >= node->val) {
            if (!first) first = prev;
            else second = node;
        } */
        if (!first && prev->val >= node->val) first = prev;
        if (first && prev->val >= node->val) second = node; // this might be executed twice, then second time value is what we want if so
        prev = node;
        dfs(node->right);
    }
    void recoverTree(TreeNode* root) { // swapping the val
        dfs(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
