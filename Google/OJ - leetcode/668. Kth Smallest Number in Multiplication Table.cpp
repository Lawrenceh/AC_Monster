/* binary search */
class Solution {
public:
    int countNumbers(int m, int n, int k, int t) {
        /* count the numbers <= t */
        int cnt = 0;
        for (int i = 1; i <= m; i ++) {
            cnt += min(t / i, n); // when n is small, we need to pick the smaller one
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countNumbers(m, n, k, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
