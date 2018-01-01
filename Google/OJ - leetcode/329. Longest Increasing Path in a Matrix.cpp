/* dfs + dp */
/* NOTE: this is true in mid of 4 directional searches because if we search one of the directions, in its next step search, we will not come back again because of strictly increasing condition check before the search */
class Solution {
public:
    int m, n;
    int dfs(vector<vector<int> >& matrix, vector<vector<int> >& dp, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        if (dp[i][j]) return dp[i][j];
        if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) dp[i][j] = max(dp[i][j], dfs(matrix, dp, i + 1, j));
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) dp[i][j] = max(dp[i][j], dfs(matrix, dp, i - 1, j));
        if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) dp[i][j] = max(dp[i][j], dfs(matrix, dp, i, j + 1));
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) dp[i][j] = max(dp[i][j], dfs(matrix, dp, i, j - 1));
        return ++dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int> > dp = vector<vector<int> >(m, vector<int>(n, 0)); 
        int ret = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                ret = max(ret, dfs(matrix, dp, i, j));
            }
        }
        return ret;
    }
};
