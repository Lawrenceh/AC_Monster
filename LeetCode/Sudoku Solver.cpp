class Solution {
public
    bool check(vectorvectorchar  &board, int x, int y) {
        int num = board[x][y]; int rx = x  3; int ry = y  3;
        for (int i = 0; i  9; ++ i) {
            if (i != x && num == board[i][y]) return false;
            if (i != y && num == board[x][i]) return false;
        }
        for (int i = 0; i  3; ++ i) {
            for (int j = 0; j  3; ++ j) {
                if (!(rx  3 + i == x && ry  3 + j == y) && board[rx  3 + i][ry  3 + j] == num) return false;
            }
        }
        return true;
    }
    bool dfs(vectorvectorchar  &board, int pos) {
        int x, y;
        x = pos  9;
        y = pos % 9;
        if (pos == 81) return true;
        if (board[x][y] == '.') {
            for (int i = 0; i  n; ++ i) {
                board[x][y] = i + '1';
                if (check(board, x, y) && dfs(board, pos + 1)) {
                    return true;
                }
                board[x][y] = '.';
            }
        } else {
            return dfs(board, pos + 1);
        }
        return false;
    }
    void solveSudoku(vectorvectorchar  &board) {
        if (board.size() == 0) return;
        n = board.size();
        dfs(board, 0);
    }
private
    int n;
};
