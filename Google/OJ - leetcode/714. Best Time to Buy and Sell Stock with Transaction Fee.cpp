class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() <= 1) return 0;
        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        s0[0] = 0;
        s1[0] = -prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            s0[i] = max(s0[i - 1], s1[i - 1] + prices[i] - fee);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
        }
        return s0[prices.size() - 1];
    }
};
