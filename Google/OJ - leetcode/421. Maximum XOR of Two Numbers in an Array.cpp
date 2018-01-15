class Solution {
public:
    int findMaximumXOR(vector<int>& nums) { // Another solution: Trie implementation
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; i --) {
            mask |= (1 << i);
            set<int> s;
            for (auto x: nums) {
                s.insert(mask & x);
            }
            // t is the temporary current/latest (from MSB downwards) expected result with the ith MSB
            int t = res | (1 << i);
            for (auto x: s) {
                if (s.count(x ^ t)) { // see if we can find a certain y, by which we can have x ^ y = t, NOTE: x, y both in set s
                    res = t; // if there does exist one, we update this MSB as 1, update res and go for next bit
                    break;
                }
            }
        }
        return res;
    }
};

/* Trie Solution - use Trie to represent each number's bit representation and try to find its opposite for each word later */
/* Trie used here acts as a hash table, which helps avoid O(n^2) iteration */
/*
class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode () {next[0] = NULL; next[1] = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int helper(TreeNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};
*/

