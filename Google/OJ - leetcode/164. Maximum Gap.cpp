/* Bucketing idea without internal sorting: only local max and min needed */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> maxbuckets(n - 1, INT_MIN);
        vector<int> minbuckets(n - 1, INT_MAX);
        int max_value = INT_MIN, min_value = INT_MAX;
        for (auto i: nums) {
            max_value = max(max_value, i);
            min_value = min(min_value, i);
        }
        if (max_value == min_value) return 0; // special case
        int gap = int(ceil(double((max_value - min_value)) / (n - 1))), pos; // handling for 0 gap by division
        for (auto i: nums) {
            pos = (i - min_value) / gap;
            maxbuckets[pos] = max(maxbuckets[pos], i);
            minbuckets[pos] = min(minbuckets[pos], i);
        }
        int prev = min_value;
        int mgap = INT_MIN;
        for (int i = 0; i < n - 1; i ++) {
            if (minbuckets[i] == INT_MAX) continue;
            mgap = max(mgap, minbuckets[i] - prev);
            prev = maxbuckets[i];
        }
        mgap = max(mgap, max_value - prev);
        return mgap;
    }
};
