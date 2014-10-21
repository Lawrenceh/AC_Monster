class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(); int profit = 0;
        if (n == 0 || n == 1) return 0;
        int *history = new int[n];
        int *future = new int[n];
        memset(history, 0, n * sizeof(int));
        memset(future, 0, n * sizeof(int));
        int minimum = 1 << 15, maximum = 0;
        for (int i = 0; i < n; i ++) {
            minimum = min(minimum, prices[i]);
            if (i != 0) {
                history[i] = max(history[i - 1], prices[i] - minimum);
            }
        }
        for (int i = n - 1; i >= 0; -- i) {
            maximum = max(maximum, prices[i]);
            if (i != n - 1) {
                future[i] = max(future[i + 1], maximum - prices[i]);
            }
            profit = max(profit, history[i] + future[i]);
        }
        return profit;
    }
};
