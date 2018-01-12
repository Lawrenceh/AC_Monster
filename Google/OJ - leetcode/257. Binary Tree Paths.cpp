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
    vector<string> res;
    void dfs(TreeNode *node, string s) {
        if (!node) return;
        if (!node->left && !node->right) {
            s = s + "->" + to_string(node->val);
            res.push_back(s.substr(2));
            return;
        }
        dfs(node->left, s + "->" + to_string(node->val));
        dfs(node->right, s + "->" + to_string(node->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};
