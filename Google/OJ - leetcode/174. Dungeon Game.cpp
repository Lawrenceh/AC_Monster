/* dp (could be optimized to O(n) */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0)); // dp[i][j]: min hp needed at pos (i, j) BEFORE curr cell calculation
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                } else if (i == m - 1) {
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                } else if (j == n - 1) {
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                } else {
                    // min inside because we are trying to find the min health so that we could reach to pos (i, j)
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]); 
                }
            }
        }
        return dp[0][0];
    }
};
