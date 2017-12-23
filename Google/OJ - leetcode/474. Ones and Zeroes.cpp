/* dp */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                dp[i][j] = 0;
            }
        }
        for (auto s: strs) {
            int c0 = 0, c1 = 0;
            for (auto c: s) {
                if (c == '1') c1 ++;
                else c0 ++;
            }
            for (int i = m; i >= c0; i --) {
                for (int j = n; j >= c1; j --) {
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
                }
            }    
        }
        return dp[m][n];
    }
};
