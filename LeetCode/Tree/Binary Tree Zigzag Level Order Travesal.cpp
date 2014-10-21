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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> v;
        res.clear(); v.clear();
        if (root == NULL) return res;
        stack<TreeNode *> s1, s2; bool flag = false; s1.push(root);
        TreeNode *node = root;
        while (!s1.empty()) {
            node = s1.top();
            if (flag == false) {
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            } else {
                if (node->right) s2.push(node->right);
                if (node->left) s2.push(node->left);
            }
            v.push_back(node->val);
            s1.pop();
            if (s1.empty()) {
                res.push_back(v);
                v.clear();
                s1.swap(s2);
                flag = !flag;
            }
        }
        return res;
    }
};
