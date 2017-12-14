/* dp - plug the next element to different positions */
class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1000000007;
        vector<vector<long> > dp(n + 1, vector<long>(k + 1, 0));
        dp[1][0] = 1;
        for (int i = 2; i <= n; i ++) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(k, i * (i - 1) / 2); j ++) {
                if (j >= i) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - i] + mod; // avoid negative modded 
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                dp[i][j] %= mod;
            }
        }
        return (int)(dp[n][k]);
    }
};
