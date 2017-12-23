/* naive dfs */
class Solution {
public:
    int dp[21];
    int dfs(vector<int> &nums, int n, int s, int pos) {
        int cnt = 0;
        if (pos == n) {
            return s == 0;
        }
        cnt += dfs(nums, n, s - nums[pos], pos + 1);
        cnt += dfs(nums, n, s + nums[pos], pos + 1);
        return cnt;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0) return 0;
        return dfs(nums, n, S, 0);
    }
};

/* better solution - dp on SUM, and convert problem to partial sum problem */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   
    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums) {
            for (int i = s; i >= n; i--) { // backwards using previous record ONLY ONCE
                dp[i] += dp[i - n];
            }
        }
        return dp[s];
    }
};
