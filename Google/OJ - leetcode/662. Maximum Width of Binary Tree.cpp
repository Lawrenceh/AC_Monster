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
    int distance = 1;
    vector<int> v; // left most number id, at each level
    void preorder(TreeNode *node, int id, int depth) {
        if (!node) return;
        if (depth >= v.size()) v.push_back(id); // preorder makes sure we always push the leftmost node for this level
        else distance = max(distance, id - v[depth] + 1);
        preorder(node->left, id * 2, depth + 1);
        preorder(node->right, id * 2 + 1, depth + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        preorder(root, 1, 0);
        return distance;
    }
};
