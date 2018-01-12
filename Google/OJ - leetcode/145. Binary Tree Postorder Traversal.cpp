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
    vector<int> postorderTraversal(TreeNode* root) {
        /* Three changes from inorder traversal:
         * 1. need to check current node's right child, and push that if possible to stack for earlier visit
         * 2. need to redefine a TreeNode* in "else" branch
         * 3. we don't pop after we inspect top (only pop after the visit)
         */
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        TreeNode *node = root;
        TreeNode *prev = nullptr;
        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode *t = st.top(); // if we use node = st.top(), it's wrong because we should update its right subtree first (also, if code goes to below else branch, node stays as current "parent" node, which is a re-visit!)
                if (t->right != nullptr && t->right != prev) {
                    node = t->right; 
                } else { // right subtree is done, visit current "parent" node
                    res.push_back(t->val);
                    prev = t;
                    st.pop();
                }
            }
        }
        return res;
    }
};
