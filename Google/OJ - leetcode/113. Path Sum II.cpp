/* dfs w/ target */
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
    void dfs(vector<vector<int> >&res, vector<int>& path, TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (!(root->left) && !(root->right) && sum == root->val) res.push_back(path);
        dfs(res, path, root->left, sum - root->val);
        dfs(res, path, root->right, sum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        if (root == NULL) return res;
        dfs(res, path, root, sum);
        return res;
    }
};
