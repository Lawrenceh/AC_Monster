/* solution 1: dfs */
class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int &k) {
        if (!root) return;
        if (k == 0) return; // pruning
        dfs(root->left, k);
        --k; // visit node "root"
        if (k == 0) { // if there's no more node left to visit
            ans = root->val;
            return;
        }
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};

/* solution 2: binary search */
class Solution {
public:
    int countNodes(TreeNode *node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int n = countNodes(root->left);
        if (n >= k) {
            return kthSmallest(root->left, k);
        } else if (n < k - 1) {
            return kthSmallest(root->right, k - n - 1);
        } else { // n == k - 1
            return root->val;
        }
    }
};
