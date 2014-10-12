class Solution {
public:
    int sqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int h = 0;
        while ((unsigned long)(1 << h) * (unsigned long)(1 << h) <= x) {
            ++ h;
        }
        -- h;
        int b = h - 1;
        unsigned long res = (unsigned long)(1 << h);
        while (b >= 0) {
            if ((unsigned long)(res | (1 << b)) * (unsigned long)(res | (1 << b)) <= x) {
                res |= (1 << b);
            }
            -- b;
        }
        return (int)res;
    }
};
/*
class Solution{
public:
    int sqrt(int x) {
        if (x == 0) return 0;
        unsigned long ans = 0;
        unsigned long bit = 1l << 15;
        while (bit > 0) {
            ans |= bit;
            if (ans * ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }
        return (int)ans;
    }
};
*/
