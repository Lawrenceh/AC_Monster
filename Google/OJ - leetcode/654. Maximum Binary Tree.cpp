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
    TreeNode* construct(vector<int> &nums, int begin, int end) {
        if (begin > end) return NULL;
        int max_idx = begin, max_val = nums[begin];
        for (int i = begin; i <= end; i ++) {
            if (nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
        }
        TreeNode *root = new TreeNode(nums[max_idx]);
        root->left = construct(nums, begin, max_idx - 1);
        root->right = construct(nums, max_idx + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};
