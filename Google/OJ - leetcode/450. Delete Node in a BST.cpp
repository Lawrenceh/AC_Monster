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
    TreeNode* f(TreeNode* root, int key) {
        if (!root) return root;
        if (key < root->val) root->left = f(root->left, key);
        else if (key > root->val) root->right = f(root->right, key);
        else {
            if (root->left && root->right) {
                // find the inorder successor (the min of right sub-tree)
                TreeNode *next = root->right;
                while (next->left) next = next->left;
                root->val = next->val;
                root->right = f(root->right, next->val);
            } else if (root->left) {
                return root->left;
            } else if (root->right) {
                return root->right;
            } else {
                return NULL;
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        root = f(root, key);
        return root;
    }

};
