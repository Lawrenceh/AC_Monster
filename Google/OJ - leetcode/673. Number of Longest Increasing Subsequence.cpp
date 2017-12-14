/* LIS w/ count */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int dp[n];
        int c[n];
        fill_n(dp, n, 1); // memset doesn't work!
        fill_n(c, n, 1);
        int ans = 0;
        int max_len = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        c[i] = c[j];
                    } else if (dp[i] == dp[j] + 1) {
                        c[i] += c[j];
                    }
                }
            }
            // need to check if max_len is updated: if not, then we need to accumalate results
            if (dp[i] > max_len) {
                max_len = dp[i];
                ans = c[i];
            } else if (dp[i] == max_len) {
                ans += c[i];
            }
        }
        return ans;
    }
};
