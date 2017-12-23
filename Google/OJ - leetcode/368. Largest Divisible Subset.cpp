/* dp with parent backtracing array */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        int n = nums.size();
        if (n == 0) return v;
        if (n == 1) return nums;
        int dp[n];
        int parent[n];
        int maxl = 1;
        int maxi = 0;
        fill_n(dp, n, 1);
        fill_n(parent, n, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                    if (dp[i] > maxl) {
                        maxl = dp[i];
                        maxi = i;
                    }
                }
            }
        }
        int j = maxi;
        while (maxl != 0) {
            v.push_back(nums[j]);
            j = parent[j];
            maxl --;
        }
        return v;
    }
};
