class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        if (n == 0) return {};
        vector<int> res(n, 0);
        int i = 0;
        while (i < n) {
            if (stk.empty()) {
                stk.push(i++);
            } else {
                if (temperatures[i] <= temperatures[stk.top()]) {
                    stk.push(i++);
                } else { // pop top
                    int idx = stk.top();
                    stk.pop();
                    res[idx] = i - idx;
                }
            }
        }
        // handle last several elements
        while (!stk.empty()) {
            res[stk.top()] = 0;
            stk.pop();
        }
        return res;
    }
};
