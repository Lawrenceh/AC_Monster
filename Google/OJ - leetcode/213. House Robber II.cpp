/* based on problem i */
class Solution {
public:
    int f(vector<int> v) {
        int n = v.size();
        if (n == 0) return 0;
        int dp[n];
        fill_n(dp, n, 0);
        dp[0] = v[0];
        if (n == 1) return dp[0];
        dp[1] = max(v[0], v[1]);
        for (int i = 2; i < n; i ++) {
            dp[i] = max(dp[i - 1], v[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        // dp: condition on the first element chosen or not
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else {
            vector<int> v1(nums.begin() + 2, nums.begin() + nums.size() - 1);
            vector<int> v2(nums.begin() + 1, nums.begin() + nums.size());
            return max(nums[0] + f(v1), f(v2));
        }
    }
};
