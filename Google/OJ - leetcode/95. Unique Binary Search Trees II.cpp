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
    vector<TreeNode*> generate(int begin, int end) {
        vector<TreeNode*> v;
        if (begin > end) { // won't cover generate(1, 0) case
            v.push_back(nullptr);
            return v;
        }
        if (begin == end) {
            v.push_back(new TreeNode(begin));
            return v;
        }
        for (int i = begin; i <= end; i ++) {
            auto left = generate(begin, i - 1);
            auto right = generate(i + 1, end);
            for (auto l: left) {
                for (auto r: right) {
                    // generate dot product
                    TreeNode *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    v.push_back(node);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> v;
            return v;
        }
        return generate(1, n);
    }
};
