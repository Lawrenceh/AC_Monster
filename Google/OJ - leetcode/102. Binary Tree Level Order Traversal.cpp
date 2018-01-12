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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p = root, *curr; // p: current level last node pointer, curr: last non-nullptr node (next level)
        vector<int> v;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                curr = node->left;
            }
            if (node->right) {
                q.push(node->right);
                curr = node->right;
            }
            v.push_back(node->val);
            if (node == p) {
                p = curr;
                res.push_back(v);
                v = {};
            }
        }
        return res;
    }
};
