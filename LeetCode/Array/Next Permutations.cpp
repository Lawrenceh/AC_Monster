class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int pivot = 0; int expivot = -1;
        if (n <= 1) return;
        for (int i = n - 2; i >= 0; i --) {
            if (num[i] < num[i + 1]) {
                pivot = i;
                expivot = i + 1;
                break;
            }
        }
        if (expivot == -1) { // all decreasing
            int i = 0;
            int j = n - 1;
            while (i < j) {
                swap(num[i], num[j]);
                i ++; j --;
            }
            return;
        }
        for (int i = pivot + 2; i < n; i ++) {
            if (num[i] > num[pivot] && num[i] <= num[expivot]) {
                expivot = i;
            }
        }
        swap(num[pivot], num[expivot]);
        int i = pivot + 1;
        int j = n - 1;
        while (i < j) {
            swap(num[i], num[j]);
            i ++; j --;
        }
    }
};
