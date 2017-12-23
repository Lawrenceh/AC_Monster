/* kadane algorithm + binary search w/ set */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // 2d kadane with binary search idea
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int currmax = INT_MIN;
        for (int j = 0; j < n; j ++) {
            vector<int> sums(m, 0);
            for (int jj = j; jj < n; jj ++) {
                for (int i = 0; i < m; i ++) {
                    sums[i] += matrix[i][jj];
                }
                int sum = 0;
                set<int> s;
                s.insert(0);
                for (auto x: sums) {
                    sum += x;
                    auto it = s.lower_bound(sum - k);
                    if (it != s.end()) currmax = max(currmax, sum - *it);
                    s.insert(sum);
                }
            }
        }
        return currmax;
    }
};
