class Solution {
public:
    stack<int> s;
    int res;
    int largestRectangleArea(vector<int> &height) {
        res = 0;
        height.push_back(0);
        if (height.empty()) return 0;
        s.push(0);
        for (int i = 1; i < height.size(); i ++) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int t = height[s.top()];
                s.pop();
                int lindex = (s.empty()) ? -1 : s.top();
                if (t * (i - lindex - 1) > res) res = t * (i -lindex - 1);
            }
            s.push(i);
        }
        return res;
    }
};
