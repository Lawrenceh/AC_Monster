class Solution {
public:
    int area;
    stack<int> s;
    int maximalRectangle(vector<vector<char> > &matrix) {
        area = 0;
        if (matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i ++) {
            matrix[i].push_back('0');
        }
        int *h = new int[n + 1];
        memset(h, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < m; i ++) {
            // clear stack s
            while (!s.empty()) s.pop();
            if (matrix[i][0] == '1') h[0] ++;
            else h[0] = 0;
            s.push(0);
            for (int j = 1; j < n + 1; j ++) {
                if (matrix[i][j] == '1') h[j] ++;
                else h[j] = 0;
                while (!s.empty() && h[s.top()] > h[j]) {
                    int t = h[s.top()];
                    s.pop();
                    int lindex = s.empty() ? -1 : s.top();
                    if (t * (j - lindex - 1) > area) area = t * (j - lindex - 1);
                }
                s.push(j);
            }
        }
        return area;
    }
};
