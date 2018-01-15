class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> stk;
        unordered_map<int, int> m;
        if (nums.empty()) return res;
        int i = 0;
        while (i < nums.size()) {
            if (stk.empty() || stk.top() >= nums[i]) {
                stk.push(nums[i++]);
            } else {
                m[stk.top()] = nums[i];
                stk.pop();
            }
        }
        while (!stk.empty()) {
            m[stk.top()] = -1;
            stk.pop();
        }
        for (auto e: findNums) {
            res.push_back(m[e]);
        }
        return res;
    }
};
