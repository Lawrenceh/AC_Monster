class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = A[0];
        for (int i = 1; i < n; i ++) {
            if (A[i - 1] > 0) A[i] += A[i - 1];
            if (max < A[i]) max = A[i];
        }
        return max;
    }
};
