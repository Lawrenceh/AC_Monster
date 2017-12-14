/* DP: 1) separate interval into sub-intervals 2) iterate via interval length */
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int dp[n][n]; // dp[i][j]: s[i, j]
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 1; i < n; i ++) { // i == 1: length = 2
            for (int j = 0; j < n - i; j ++) { // j: start of the interval (1st interval)
                dp[j][j + i] = i + 1; // initialize min
                for (int k = j + 1; k <= j + i; k ++) { // k: start of 2nd interval
                    int tmp = dp[j][k - 1] + dp[k][j + i];
                    if (s[k - 1] == s[j + i]) tmp --;
                    dp[j][j + i] = min(dp[j][j + i], tmp);
                }
            }
        }
        return dp[0][n - 1];
    }
};
