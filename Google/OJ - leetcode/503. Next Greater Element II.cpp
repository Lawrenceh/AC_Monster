/* hash table */
/* NOTE: in Problem 496 we use mapping from value to value, here we can't because we have duplicates. Using index mapping index */
/* Also circular cases need to be considered. But if we can't find next greater element after a cycle we assign a -1 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        stack<int> stk;
        unordered_map<int, int> m; // from index to value (there are duplicates..)
        if (nums.empty()) return res;
        int i = 0;
        while (i < nums.size()) {
            if (stk.empty() || nums[stk.top()] >= nums[i]) {
                stk.push(i++);
            } else {
                m[stk.top()] = nums[i];
                stk.pop();
            }
        }
        i = 0;
        while (!stk.empty() && i < nums.size()) {
            if (nums[stk.top()] >= nums[i]) i ++;
            else {
                m[stk.top()] = nums[i];
                stk.pop();      
            }
        }
        while (!stk.empty()) {
            m[stk.top()] = -1;
            stk.pop();
        }
        for (i = 0; i < nums.size(); i ++) {
            res.push_back(m[i]);
        }
        return res;
    }
};
