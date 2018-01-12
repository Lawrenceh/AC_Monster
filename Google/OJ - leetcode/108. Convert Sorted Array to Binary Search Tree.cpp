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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode *node = nullptr;
        if (n == 0) return node;
        int pos = n / 2;
        node = new TreeNode(nums[pos]);
        // in fact we could use low, high for indices to avoid using copies of vector
        auto left = vector<int>(nums.begin(), nums.begin() + pos);
        auto right = vector<int>(nums.begin() + pos + 1, nums.end());
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }
};
