/* O(n^2) dp - could be optimized to O(n) */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i ++) {
            dp[i][1] = sum[i];
        }
        int local_min;
        for (int j = 2; j <= m; j ++) {
            for (int i = 1; i <= n; i ++) {
                local_min = INT_MAX;
                if (i < j) continue;
                for (int k = i - 1; k >= j - 1; k --) {
                    local_min = min(local_min, max(dp[k][j - 1], sum[i] - sum[k]));
                }
                dp[i][j] = local_min;
            }
        }
        return dp[n][m];
    }
};


/*** BINARY SEARCH IDEA in java ***/
public class Solution {
    public int splitArray(int[] nums, int m) {
        int max = 0; long sum = 0;
        for (int num : nums) {
            max = Math.max(num, max);
            sum += num;
        }
        if (m == 1) return (int)sum;
        //binary search
        long l = max; long r = sum;
        while (l <= r) {
            long mid = (l + r)/ 2;
            if (valid(mid, nums, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (int)l;
    }
    public boolean valid(long target, int[] nums, int m) {
        int count = 1;
        long total = 0;
        for(int num : nums) {
            total += num;
            if (total > target) {
                total = num;
                count++;
                if (count > m) {
                    return false;
                }
            }
        }
        return true;
    }
}
