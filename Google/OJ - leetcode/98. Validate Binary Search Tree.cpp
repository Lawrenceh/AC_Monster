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
    // int prev = INT_MIN; // buggy
    TreeNode* prev = nullptr;
    bool dfs(TreeNode *node) {
        if (node == nullptr) return true;
        if (!dfs(node->left)) return false;
        if (prev != nullptr && node->val <= prev->val) return false;
        else prev = node;
        if (!dfs(node->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        // inorder traversal
        return dfs(root);
    }
};
