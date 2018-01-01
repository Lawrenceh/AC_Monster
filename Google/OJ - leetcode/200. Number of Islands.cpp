/* dfs */
class Solution {
public:
    void dfs(vector<vector<char> >&grid, vector<vector<bool> >&v, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (v[i][j] == true) return;
        v[i][j] = true; // could change 1 to 0 once found!!
        if (grid[i][j] == '0') return;
        dfs(grid, v, i + 1, j, m, n);
        dfs(grid, v, i - 1, j, m, n);
        dfs(grid, v, i, j + 1, m, n);
        dfs(grid, v, i, j - 1, m, n);
    }

    int numIslands(vector<vector<char> >& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        int cnt = 0;
        vector<vector<bool> > v(m, vector<bool>(n, false)); // no need for this
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (v[i][j] == false) {
                    dfs(grid, v, i, j, m, n);
                    if (grid[i][j] == '1') cnt ++;
                }
            }
        }
        return cnt;
    }
};
