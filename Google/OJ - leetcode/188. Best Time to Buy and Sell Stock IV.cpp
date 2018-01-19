class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        if (k >= prices.size() / 2) { // optimization
            int profit = 0;
            for (int i = 0; i < prices.size() - 1; i ++) {
                if (prices[i + 1] > prices[i]) profit += prices[i + 1] - prices[i];
            }
            return profit;
        }
        // dp[i][j]: at most i transactions till day j
        // dp[i][j] = max{dp[i][j - 1], max(dp[i - 1][kk] - prices[kk] + prices[j]), kk = 0..j-1}
        // this dp equation could be optimized for sure.. (skipped)
        vector<vector<int> > dp(k + 1, vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; i ++) {
            int local_max = dp[i - 1][0] - prices[0];
            for (int j = 1; j < prices.size(); j ++) {
                dp[i][j] = max(dp[i][j - 1], local_max + prices[j]);
                local_max = max(local_max, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][prices.size() - 1];
    }
};
