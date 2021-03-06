/* 0-1 knapsack problem DP */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 || n == 0) return false;
        sum /= 2;
        bool dp[n + 1][sum + 1]; // dp[i][j]: first ith, equal to j
        // init dp array
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= sum; j ++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 0; i <= sum; i ++) {
            dp[0][i] = false;
        }
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = true;
        }
        // iteration
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= sum; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i - 1]]);
                }
            }
        }
        return dp[n][sum];
    }
};
