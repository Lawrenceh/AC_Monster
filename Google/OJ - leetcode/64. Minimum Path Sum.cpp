class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (j == 0) dp[j] += grid[i][j];
                else dp[j] = min((i == 0) ? INT_MAX : dp[j], dp[j - 1]) + grid[i][j];               
            }
        }
        return dp[n - 1];
    }
};
