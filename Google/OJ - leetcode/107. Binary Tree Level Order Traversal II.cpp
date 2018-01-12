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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // count number of level nodes
        vector<vector<int> > res;
        stack<vector<int> > st;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        // curr counter
        int curr = 0;
        TreeNode *node;
        vector<int> v;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                    curr ++;
                }
                if (node->right) {
                    q.push(node->right);
                    curr ++;
                }
            }
            st.push(v);
            v = {};
            curr = 0;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
