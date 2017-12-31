/* binary search: to calculate kth ?value?, binary search on [min, max] of possible values */
class Solution {
public:
    /* count the number of elements <= target */
    int countPairs(vector<int> &v, int t) {
        /* sliding window */
        int n = v.size();
        int ret = 0;
        for (int i = 0; i < n; i ++) {
            int j = i + 1;
            while (j < n && v[j] - v[i] <= t) j ++;
            ret += j - i - 1;
        }
        return ret;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
