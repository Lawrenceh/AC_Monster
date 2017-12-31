/* binary search */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            // counting elements <= mid
            int cnt = 0, j = n - 1;
            for (int i = 0; i < n; i ++) {
                while (j >= 0 && matrix[i][j] > mid) j --;
                cnt += (j + 1);
            }
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
