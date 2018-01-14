/* solution using algorithm used in largestRectangleArea problem 84: stack */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> v(matrix[0].size(), 0);
        int area = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {
                if (matrix[i][j] == '0') v[j] = 0;
                else v[j] ++;
            }
            area = max(largestRectangleArea(v), area);
        }
        return area;
    }
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
