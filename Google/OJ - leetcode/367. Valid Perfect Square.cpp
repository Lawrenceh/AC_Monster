class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left = 1, right = num / 2;
        while (left <= right) {
            long mid = left + (right - left) / 2; // type long for avoiding integer overflow
            if (mid * mid == num) return true;
            else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

/* math representation 1 + 3 + 5 + ... */
public boolean isPerfectSquare(int num) {
     int i = 1;
     while (num > 0) {
         num -= i;
         i += 2;
     }
     return num == 0;
 }

/* Newton method */
public boolean isPerfectSquare(int num) {
    long x = num;
    while (x * x > num) {
        x = (x + num / x) >> 1;
    }
    return x * x == num;
}
