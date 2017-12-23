/* O(n*n) dp */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n];
        fill_n(dp, n, 1);
        int ans = 1;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] % 2 == 0) {
                    if (nums[i] < nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                } else {
                    if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        // flip side of postive and negative
        fill_n(dp, n, 1);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] % 2 == 0) {
                    if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                } else {
                    if (nums[i] < nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

/* O(n) DP with different definition of dp[i]!!! */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        
        vector<int> up(size, 0);
        vector<int> down(size, 0);
        
        up[0] = 1;
        down[0] = 1;
        for(int i=1; i<size; ++i){
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[size-1], down[size-1]);
    }
};
