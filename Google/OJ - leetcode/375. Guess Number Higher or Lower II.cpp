/* tricky dp: MINIMAX problem */
class Solution {
public:
    int dp[1001][1001];
    int dfs(int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r]) return dp[l][r];
        int ret = INT_MAX;
        for (int i = l; i <= r; i ++) {
            ret = min(ret, i + max(dfs(l, i - 1), dfs(i + 1, r)));
        }
        dp[l][r] = ret;
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= n; j ++) {
                dp[i][j] = 0;
            }
        }
        return dfs(1, n);
    }
};
