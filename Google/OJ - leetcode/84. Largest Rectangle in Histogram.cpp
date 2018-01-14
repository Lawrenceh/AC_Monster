class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        int i = 0;
        int sum = 0;
        while (i < n) {
            if (st.empty() || heights[i] > heights[st.top()]) st.push(i++);
            else { // pop and calc
                int idx = st.top();
                st.pop();
                if (st.empty()) { // no left bound, use default one
                    sum = max(sum, i * heights[idx]);
                } else {
                    sum = max(sum, (i - st.top() - 1) * heights[idx]);
                }
            }
        }
        return sum;
    }
};
