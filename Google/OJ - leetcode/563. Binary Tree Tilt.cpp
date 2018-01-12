/* better solution, using "tilt" global variable along with traversal keeping track of sum of all nodes in sub-tree */
class Solution {
public:
    int tilt = 0;
    int traverse(TreeNode *node) { // return sum of all nodes
        if (!node) return 0;
        int left = traverse(node->left);
        int right = traverse(node->right);
        tilt += abs(left - right);
        return left + right + node->val;
    }
    int findTilt(TreeNode* root) {
        traverse(root);
        return tilt;
    }
};


/* initial submission */
class Solution {
public:
    pair<int, int> find(TreeNode *node) {
        // traverse tree, and return not only its tilt but also its sum of all nodes
        if (!node) return make_pair(0, 0);
        auto p1 = find(node->left);
        auto p2 = find(node->right);
        return make_pair(p1.first + p2.first + abs(p1.second - p2.second), p1.second + p2.second + node->val);
    }
    int findTilt(TreeNode* root) {
        return find(root).first;
    }
};
