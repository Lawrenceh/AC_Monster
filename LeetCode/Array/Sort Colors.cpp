// 1. quicksort partitioning and do the two-sides twice
class Solution {
public:
    void swap(int a[], int i, int j) {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }
    void sortColors(int A[], int n) {
        int i = 0, j = n - 1;
        int firstOne = -1, firstTwo = -1, lastZero = -1, lastOne = -1;
        while (i < j) {
            while (A[i] != 2 && i < n) i ++;
            if (i >= j) break;
            while (A[j] != 0 && j > 0) j --;
            if (i >= j) break;
            swap(A, i, j);
        }
        for (int k = 0; k < n; k ++) {
            if (firstOne == -1 && A[k] == 1) firstOne = k;
            if (firstTwo == -1 && A[k] == 2) firstTwo = k;
            if (A[k] == 0) lastZero = k;
            if (A[k] == 1) lastOne = k;
        }
        if (firstOne == -1) return;
        else {
            if (firstTwo == -1) {
                i = 0; j = n - 1;
                while (i < j) {
                    while (A[i] != 1 && i < n) i ++;
                    if (i >= j) break;
                    while (A[j] != 0 && j > 0) j --;
                    if (i >= j) break;
                    swap(A, i, j);
                }
            } else if (lastZero == -1) {
                i = 0; j = n - 1;
                while (i < j) {
                    while (A[i] != 2 && i < n) i ++;
                    if (i >= j) break;
                    while (A[j] != 1 && j > 0) j --;
                    if (i >= j) break;
                    swap(A, i, j);
                }
            } else { // 0, 1, 2 all exist
                if (firstOne < lastZero) {
                    i = firstOne; j = lastZero;
                    while (i < j) {
                        while (A[i] != 1 && i < n) i ++;
                        if (i >= j) break;
                        while (A[j] != 0 && j > 0) j --;
                        if (i >= j) break;
                        swap(A, i, j);
                    }
                }
                if (firstTwo < lastOne) {
                    i = firstTwo; j = lastOne;
                    while (i < j) {
                        while (A[i] != 2 && i < n) i ++;
                        if (i >= j) break;
                        while (A[j] != 1 && j > 0) j --;
                        if (i >= j) break;
                        swap(A, i, j);
                    }
                }
            }
        }
    }
};

// 2. counting sort (first count and then rewrite)

// 3. revised counting sort 
public void sortColors(int[] A) {
    int i=-1, j=-1, k=-1;
    for(int p = 0; p < A.length; p++) {
        if(A[p] == 0) {
            A[++k]=2;
            A[++j]=1;
            A[++i]=0;
        }
        else if (A[p] == 1) {
            A[++k]=2;
            A[++j]=1;
        }
        else if (A[p] == 2) {
            A[++k]=2;
        }
    }
}

// 4. scan for 0 and 2 once
