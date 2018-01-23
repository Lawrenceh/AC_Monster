class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = (int) sqrt(c);
        while (left < right) {
            int val = left * left + right * right;
            if (val == c) return true;
            else if (val > c) right --;
            else left ++;
        }
        return (left * left + right * right == c);
    }
};
