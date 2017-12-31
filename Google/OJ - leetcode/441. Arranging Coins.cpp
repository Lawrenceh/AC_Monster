/* typical binary search */
class Solution {
public:
    int arrangeCoins(int n) { /* math solution not included */
        if (n == 0) return 0;
        long left = 1, right = n;
        while (left < right) {
            long mid = left + (right - left + 1) / 2; // caution!
            if (mid * (mid + 1) / 2 > n) {
                right = mid - 1; // when right = mid - 1, we need to select the 2nd one in 2 adjacent elements!
            } else {
                left = mid;
            }
        }
        return left;
    }
};
