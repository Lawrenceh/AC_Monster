/* 3D dp */
class Solution {
public:
    int dfs(vector<int> &v, int i, int j, int k, int dp[101][101][101]) {
        if (dp[i][j][k] != 0) return dp[i][j][k];
        if (i > j) return 0; // only == check is not enough because of below comment
        int res = (k + 1) * (k + 1) + dfs(v, i + 1, j, 0, dp);
        for (int q = i + 1; q <= j; q ++) {
            if (v[q] == v[i]) res = max(res, dfs(v, i + 1, q - 1, 0, dp) + dfs(v, q, j, k + 1, dp)); // i + 1 could be larger than q - 1
        }
        dp[i][j][k] = res;
        return dp[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[101][101][101] = {0};
        return dfs(boxes, 0, n - 1, 0, dp);
    }
};
