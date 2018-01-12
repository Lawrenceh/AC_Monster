/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*> v;
    int idx;
    BSTIterator(TreeNode *root) {
        idx = 0;
        if (!root) return;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                v.push_back(node);
                node = node->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (idx < v.size());
    }

    /** @return the next smallest number */
    int next() {
        return v[idx++]->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
