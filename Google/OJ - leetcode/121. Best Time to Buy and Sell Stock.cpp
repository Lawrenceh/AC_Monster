class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int local_min = INT_MAX;
        for (auto p: prices) {
            if (p < local_min) local_min = p;
            res = max(res, p - local_min);
        }
        return res;
    }
};
