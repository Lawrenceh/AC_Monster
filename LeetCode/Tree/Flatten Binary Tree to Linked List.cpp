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
    void flatten(TreeNode *root) {
        while (root) {
            if (root->left) {
                TreeNode *ptr = root->left;
                while (ptr->right) ptr = ptr->right;
                ptr->right = root->right;
                // ptr->left = NULL;
                // what if there is no right child!
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};

class Solution {
    TreeNode *preNode;
public:
    void f(TreeNode *node) {
        if (node == NULL) return;
        TreeNode *p = node->right; // record the current right child since it will be changed in f(node->left)!
        if (preNode != NULL) {
            preNode->left = NULL;
            preNode->right = node;
        }
        preNode = node;
        f(node->left);
        f(p);
    }
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        preNode = NULL;
        f(root);
    }
};
