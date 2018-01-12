/* solution 1: divide and conquer, using MergeSort idea */
/* solution 2: level order traversal */
/* solution 3: traversal with height value mapping */

class Solution {
public:
    void traverse(map<int, int> &m, TreeNode* root, int height){
        /* traverse with stored height-value pairs */
        if (root == NULL) return;
        if (m.find(height) == m.end()) m[height] = root->val;
        m[height] = max(m[height], root->val);
        traverse(m, root->left, height + 1);
        traverse(m, root->right, height + 1);
    }
    vector<int> traverse2(TreeNode* root) {
        /* divide and conquer */
        vector<int> v, v_left, v_right;
        if (root == NULL) return v;
        v.push_back(root->val);
        v_left = traverse2(root->left);
        v_right = traverse2(root->right);
        int i = 0, j = 0;
        for (; i < v_left.size() && j < v_right.size(); i ++, j ++) {
            v.push_back(max(v_left[i], v_right[j]));
        }
        while (i < v_left.size()) v.push_back(v_left[i++]);
        while (j < v_right.size()) v.push_back(v_right[j++]);
        return v;
    }
    vector<int> largestValues(TreeNode* root) {
        /*
        map<int, int> m;
        traverse(m, root, 0);
        vector<int> v;
        for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter ++) {
            v.push_back(iter->second);
        }
        return v;
        */
        return traverse2(root);
    }
};
