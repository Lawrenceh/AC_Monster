/* fibonacii, dp */
class Solution {
public:
    int findIntegers(int num) {
        int a[32];
        fill_n(a, 32, 0);
        a[0] = 1;
        a[1] = 2;
        for (int j = 2; j < 32; j ++) {
            a[j] = a[j - 1] + a[j - 2];
        }
        int i = 31;
        int ans = 0;
        bool flag = false; // flag is used for keeping track of "11"s (if so break)
        while (i >= 0) { // find the current msb 1
            if (num & (1 << i)) {
                ans += a[i];
                if (flag) return ans;
                flag = true;
            } else {
                flag = false;
            }
            i --;
        }
        return ans + 1;
    }
};
