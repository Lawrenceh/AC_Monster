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
    int cnt = 0;
    int prev = 0;
    int freq = 0; // max freq
    vector<int> v; // max freq ans
    void traverse(TreeNode *node) {
        if (!node) return;
        traverse(node->left);
        if (cnt == 0) {
            prev = node->val;
            cnt = 1;
        } else {
            if (node->val == prev) cnt ++;
            else {
                if (cnt > freq) {
                    v = {prev};
                    freq = cnt;
                } else if (cnt == freq) {
                    v.push_back(prev);
                }
                prev = node->val;
                cnt = 1;
            }
        }
        traverse(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        if (cnt == 0) return v;
        else if (cnt == freq) v.push_back(prev);
        else if (cnt > freq) v = {prev};
        return v;
    }
};
