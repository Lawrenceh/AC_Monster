class Solution {
public:
    /* O(mn) space DP */
    int dp[1001][1001]; // dp[i][j]: ends with A[i - 1] and B[j - 1] (to save extra code block for length 1 cases)
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        if (m == 0 || n == 0) return 0;
        int l = 0;
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    l = max(l, dp[i][j]);
                }
            }
        }
        return l;
    }

    /* backwards O(n) space DP */
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        if (m == 0 || n == 0) return 0;
        int l = 0;
        int dp[1001];
        memset(dp, 0, sizeof(int) * 1001);
        for (int i = 1; i <= m; i ++) {
            for (int j = n; j >= 1; j --) {
                if (A[i - 1] == B[j - 1]) {
                    dp[j] = 1 + dp[j - 1];
                } else {
                    dp[j] = 0; // reset if they don't match
                }
                l = max(l, dp[j]);
            }
        }
        return l;
    }
};
