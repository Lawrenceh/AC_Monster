/* Greedy */
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int k = 2;
        while (n != 1) {
            if (n % k == 0) {
                ans += k;
                n /= k;
            } else {
                k ++;
            }
        }
        return ans;
    }
};
