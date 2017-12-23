/* reverse dp idea! */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int a[n + 2];
        a[0] = a[n + 1] = 1;
        for (int i = 1; i <= n; i ++) {
            a[i] = nums[i - 1];   
        }
        n += 2; // adjust n to n + 2
        int dp[n + 1][n + 1] = {}; // default zeros
        for (int k = 2; k <= n - 1; k ++) {
            for (int left = 0; left + k < n; left ++) {
                int right = left + k;
                for (int i = left + 1; i < right; i ++) {
                    dp[left][right] = max(dp[left][right], a[left] * a[i] * a[right] + dp[left][i] + dp[i][right]); // dp[i][i + 1] are 0's
                }
            }
        }
        return dp[0][n - 1];
    }
};
