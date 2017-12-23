/* dp */
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        // dp[i][j]: rotating for key[i:] and current position is j
        int dp[n + 1][m]; // one more for length 0 base case in dp iteration
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j < m; j ++) {
                dp[i][j] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int j = 0; j < m; j ++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < m; k ++) {
                    if (ring[k] == key[i]) {
                        int dis = abs(k - j);
                        dp[i][j] = min(dp[i][j], min(dis, m - dis) + dp[i + 1][k] + 1);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
