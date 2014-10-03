class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int x = (m + n + 1) >> 1;
        int y = (m + n + 2) >> 1;
        return (findK(A, m, B, n, x) + findK(A, m, B, n, y)) / 2.0;
    }
    int findK(int a[], int m, int b[], int n, int k) {
        if (m == 0) return b[k - 1];
        if (n == 0) return a[k - 1];
        if (k == 1) return min(a[0], b[0]);
        int i = min(m, k / 2), j = min(n, k / 2);
        if (a[i - 1] > b[j - 1])
            return findK(a, m, b + j, n - j, k - j);
        else
            return findK(a + i, m - i, b, n, k - i);
        return 0;
        //int mida = m / 2;
        //int midb = n / 2;
        //int halflen = (m + n) / 2;
        //if (a[mida] > b[midb]) {
        //    if (halflen > k) return findK(a, m / 2, b, n, k);
        //    else return findK(a, m, b + n / 2, n / 2, k - n / 2);
        //}
        //else {
        //    if (halflen > k) return findK(a, m, b, n / 2, k);
        //    else return findK(a + m / 2, m / 2, b, n, k - m / 2);
        //}
    }
};
