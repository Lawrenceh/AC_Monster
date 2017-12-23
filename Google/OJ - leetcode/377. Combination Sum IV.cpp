/* 2d dp on target */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        fill_n(dp, target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i ++) {
            for (auto n: nums) {
                if (i >= n) {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};
