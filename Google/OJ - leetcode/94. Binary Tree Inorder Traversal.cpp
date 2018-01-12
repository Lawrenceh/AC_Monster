/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/* iterative */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (!root) return res;
        TreeNode *node = root;
        while (!st.empty() || node != NULL) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                // left is searched
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};


/* MORRIS TRAVERSAL - Threaded Binary Tree */
/* SEE: https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *curr = root, *prev;
        // morris traversal (threaded binary tree)
        while (curr) {
            if (curr->left == nullptr) { // left is searched, visit curr and move forward to right subtree
                // visit
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                // find predecessor
                prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) { // add thread
                    prev->right = curr;
                    curr = curr->left;
                } else { // visit node and remove thread
                    prev->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};



/* initial submission, both recursive and iterative */
class Solution {
public:
    vector<int> v;
    stack<TreeNode*> st;
    void dfs(TreeNode *node) {
        if (!node) return;
        dfs(node->left);
        v.push_back(node->val);
        dfs(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //dfs(root);
        TreeNode *node = root;
        while (node != NULL || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            v.push_back(node->val);
            node = node->right;
        }
        return v;
    }
};
