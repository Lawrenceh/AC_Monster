/* could be optimized to O(1) space dp */
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        f(0) = nums[0]
        f(1) = max(num[0], num[1])
        f(k) = max( f(k-2) + nums[k], f(k-1) )
        */
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n];
        fill_n(dp, n, 0);
        dp[0] = nums[0];
        if (n == 1) return dp[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i ++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};
