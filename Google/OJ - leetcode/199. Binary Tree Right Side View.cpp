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
    vector<int> res;
    void dfs(TreeNode *root, int h) {
        if (!root) return;
        if (res.size() == h) res.push_back(root->val);
        dfs(root->right, h + 1);
        dfs(root->left, h + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
