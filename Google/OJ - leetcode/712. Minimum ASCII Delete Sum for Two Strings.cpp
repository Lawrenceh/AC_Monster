class Solution {
public:
    /* O(mn) space DP, similar to ED */
    /*
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i ++) {
            if (i == 0) dp[i][0] = 0;
            else {
                dp[i][0] = dp[i - 1][0] + s1[i - 1];    
            }
        }
        for (int j = 0; j <= n; j ++) {
            if (j == 0) dp[0][j] = 0;
            else {
                dp[0][j] = dp[0][j - 1] + s2[j - 1];
            }
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                }
            }
        }
        return dp[m][n];
    }
    */
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int dp[n + 1];
        for (int j = 0; j <= n; j ++) {
            if (j == 0) dp[j] = 0;
            else {
                dp[j] = dp[j - 1] + s2[j - 1];
            }
        }
        int t1, t2; // temporary value copies for dp[i - 1][j - 1]
        for (int i = 1; i <= m; i ++) {
            t1 = dp[0];
            dp[0] += s1[i - 1]; // update dp[0] for the first column, not always 0
            for (int j = 1; j <= n; j ++) {
                t2 = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = t1;
                } else {
                    dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }
                t1 = t2;
            }
        }
        return dp[n];
    }
};
