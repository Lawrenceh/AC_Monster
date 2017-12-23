/* dp */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n] = {0}; // dp[i][j]: the amt 1st player can win over 2nd player
        for (int i = 0; i < n; i ++) {
            dp[i][i] = nums[i];
        }
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < n - i; j ++) {
                dp[j][j + i] = max(nums[j] - dp[j + 1][j + i], nums[j + i] - dp[j][j + i - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
