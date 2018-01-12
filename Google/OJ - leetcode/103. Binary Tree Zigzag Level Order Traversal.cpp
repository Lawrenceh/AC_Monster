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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; i ++) {
                TreeNode *node = q.front();
                q.pop();
                if (level & 1) v[size - i - 1] = node->val;
                else v[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level ++;
            res.push_back(v);
        }
        return res;
    }
};
