/* dfs + dp memorization (chosen numbers) */
class Solution {
public:
    bool used[21];
    int format(bool used[21], int n) {
        int ret = 0;
        for (int i = 1; i <= n; i ++) {
            ret <<= 1;
            if (used[i]) ret |= 1;
        }
        return ret;
    }
    bool dfs(int n, int target, unordered_map<int, bool> &dp) {
        if (target <= 0) {
            return false;
        }
        int key = format(used, n);
        if (dp.count(key)) return dp[key];
        for (int i = 1; i <= n; i ++) {
            if (!used[i]) {
                used[i] = true;
                if (!dfs(n, target - i, dp)) { // 2nd player loses, which means that this is good move
                    used[i] = false;
                    dp[key] = true;
                    return true;
                }
                used[i] = false;
            }
        }
        dp[key] = false;
        return dp[key];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2; // inevitable step for optimization on large test cases
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        unordered_map<int, bool> dp;
        fill_n(used, 21, false);
        return dfs(maxChoosableInteger, desiredTotal, dp);
    }
};
