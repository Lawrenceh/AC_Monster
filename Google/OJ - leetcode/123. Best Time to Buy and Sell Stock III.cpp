class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int res = 0, local_min = INT_MAX, local_max = INT_MIN;
        int n = prices.size();
        int left[prices.size()], right[prices.size()];
        fill_n(left, prices.size(), 0);
        fill_n(right, prices.size(), 0);
        for (int i = 0, j = n - 1; i < n, j >= 0; i ++, j --) {
            if (prices[i] < local_min) local_min = prices[i];
            if (prices[j] > local_max) local_max = prices[j];
            left[i] = max(i > 0 ? left[i - 1] : 0, prices[i] - local_min);
            right[j] = max(j < n - 1 ? right[j + 1] : 0, local_max - prices[j]);
        }
        for (int i = 0; i < n; i ++) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};
