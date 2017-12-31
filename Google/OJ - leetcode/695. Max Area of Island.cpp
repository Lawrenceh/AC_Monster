/* dfs */
class Solution {
public:
    void dfs(vector<vector<int> > &grid, int i, int j, int m, int n, int &cnt) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        if (grid[i][j] == 1) {
            cnt ++;
            grid[i][j] = 0; // update matrix as visited[]
        }
        dfs(grid, i + 1, j, m, n, cnt);
        dfs(grid, i - 1, j, m, n, cnt);
        dfs(grid, i, j + 1, m, n, cnt);
        dfs(grid, i, j - 1, m, n, cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0) continue;
                int cnt = 0;
                dfs(grid, i, j, m, n, cnt);
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};
