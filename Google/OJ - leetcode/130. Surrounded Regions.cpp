/* dfs */
class Solution {
public:
    vector<vector<bool> > visited;
    void dfs(vector<vector<char> > &board, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (visited[i][j]) return;
        visited[i][j] = true;
        if (board[i][j] == 'X') return;
        // search neighboring O's
        dfs(board, i + 1, j, m, n);
        dfs(board, i - 1, j, m, n);
        dfs(board, i, j + 1, m, n);
        dfs(board, i, j - 1, m, n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++) {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j ++) {
            dfs(board, 0, j, m, n);
            dfs(board, m - 1, j, m, n);
        }
        // fill all unvisited O's into X's
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};
