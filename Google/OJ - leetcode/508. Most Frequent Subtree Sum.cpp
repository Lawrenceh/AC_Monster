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
    int maxcnt = 0;
    unordered_map<int, int> m;
    int findmaxsum(TreeNode *node) {
        if (!node) return 0;
        int sum = node->val;
        sum += findmaxsum(node->left);
        sum += findmaxsum(node->right);
        maxcnt = max(maxcnt, ++m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        findmaxsum(root);
        for (auto i: m) {
            if (i.second == maxcnt) res.push_back(i.first);
        }
        return res;
    }
};
