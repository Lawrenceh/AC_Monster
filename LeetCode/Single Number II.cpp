class Solution {
public:
    int singleNumber(int A[], int n) {
        int count = 0;
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            for (int j = 0; j < n; j ++) {
                if ((A[j] >> i) & 1) {
                    count ++;
                }
            }
            res |= ((count % 3) << i);
            count = 0;
        }
    return res;
    }
};
