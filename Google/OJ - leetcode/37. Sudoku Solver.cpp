class Solution {
public:
    bool check(vector<vector<char> > &board, int x, int y, char c) {
        for (int i = 0; i < 9; i ++) {
            if (board[i][y] == c) return false;
            if (board[x][i] == c) return false;
        }
        int row = x / 3, col = y / 3;
        for (int i = row * 3; i <= row * 3 + 2; i ++) {
            for (int j = col * 3; j <= col * 3 + 2; j ++) {
                if (board[i][j] == c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(board, i + 1, 0);
        if (board[i][j] != '.') return solve(board, i, j + 1);
        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    } 
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
