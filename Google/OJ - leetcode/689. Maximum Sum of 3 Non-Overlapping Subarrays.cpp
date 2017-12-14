/* TLE dfs solution */
class Solution {
public:
    vector<int> res;
    int getSum(vector<int> &nums, vector<int> &v, int k) {
        int sum = 0;
        for (auto i: v) {
            for (int j = 0; j < k; j ++) 
                sum += nums[i + j];
        }
        return sum;
    }
    void dfs(vector<int> &nums, int idx, int n, int curr, int k, vector<int> &v) {
        if (curr == 3) {
            if (res.empty() || getSum(nums, v, k) > getSum(nums, res, k)) res = v;
            return;
        }
        for (int i = idx; i < n; i ++) {
            if (n - i < (3 - curr) * k) return;
            v.push_back(i);
            dfs(nums, i + k, n, curr + 1, k, v);
            v.pop_back();
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v;
        dfs(nums, 0, n, 0, k, v);
        return res;
    }
};

/* left, right DP solution */
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[n + 1]; // sum[i]: first ith sum [0, i - 1] 
        int left[n]; // left[i]: [0, i]  first index of the largest sum
        int right[n];// right[i]: [i, n - 1] first index of the largest sum
        memset(sum, 0, sizeof(int) * (n + 1));
        memset(left, 0, sizeof(int) * n);
        memset(right, 0, sizeof(int) * n);
        sum[0] = 0;
        for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + nums[i - 1];
        for (int i = k - 1, s = 0; i < n - k; i ++) { // left
            if (s < sum[i + 1] - sum[i + 1 - k]) {
                left[i] = i + 1 - k;
                s = sum[i + 1] - sum[i + 1 - k];
            } else {
                left[i] = left[i - 1];
            }
        }
        for (int i = n - k, s = 0; i >= 0; i --) { // right
            if (s <= sum[i + k] - sum[i]) {
                right[i] = i;
                s = sum[i + k] - sum[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        // iterate every possible middle interval
        int m = 0, tmp = 0;
        vector<int> ans;
        for (int i = k; i <= n - k * 2; i ++) {
            tmp = sum[i + k] - sum[i] + sum[left[i - 1] + k] - sum[left[i - 1]] + sum[right[i + k] + k] - sum[right[i + k]];
            if (tmp > m) {
                m = tmp;
                ans = {left[i - 1], i, right[i + k]};
            }
        }
        return ans;
    }
};


/* 2d DP general solution, max sum of "level" number non-overlapping subarrays */
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[n + 1]; // sum[i]: first ith sum [0, i - 1] 
        memset(sum, 0, sizeof(int) * (n + 1));
        sum[0] = 0;
        for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + nums[i - 1];
        
        int level = 3;
        int dp[level + 1][n]; // dp[i][j]: the i sub-array max sum in [0, j], i starts from 1
        int idx[level + 1][n]; // idx[i][j]: the ith sub-array max sum's corresponding first idx in [0, j]
        for (int i = 0; i < level + 1; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[i][j] = 0;
                idx[i][j] = 0;
            }
        }
        
        int tmp = 0;
        for (int i = 1; i <= level; i ++) {
            for (int j = i * k - 1; j < n; j ++) {
                tmp = j < k ? sum[j + 1] : sum[j + 1] - sum[j - k + 1] + dp[i - 1][j - k];
                if (j > 0) { // special case when k = 1, j - 1 would go out of index range
                    if (tmp > dp[i][j - 1]) {
                        dp[i][j] = tmp;
                        idx[i][j] = j - k + 1;
                    } else {
                        dp[i][j] = dp[i][j - 1];
                        idx[i][j] = idx[i][j - 1];
                    }
                }
            }
        }
        
        vector<int> ans;
        for (int i = level, ii = n - 1; i > 0; i --) {
            ans.push_back(idx[i][ii]);
            ii = idx[i][ii] - 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
