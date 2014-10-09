class Solution {
public:
    void solve(vector< vector<char> > &board) {
        row = 0; column = 0;
        row = board.size();
        if (board.size() != 0) column = board[0].size();
        if (row <= 2 || column <= 2) return;
        // bfs from the Os on the boundary and mark
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][column-1] == 'O') dfs(board, i, column-1);
        }
        for (int i = 0; i < column; ++i) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[row - 1][i] == 'O') dfs(board, row - 1, i);
        }
        // mark back
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector< vector<char> > &board, int x, int y) {
        s1.push(x); s2.push(y);
        while (!s1.empty()) {
            a = s1.top(); b = s2.top();
            if (a != 0 && board[a-1][b] == 'O') {s1.push(a-1); s2.push(b); board[a-1][b] = 'B';}
            else if (a != row - 1 && board[a+1][b] == 'O') {s1.push(a+1); s2.push(b); board[a+1][b] = 'B';}
            else if (b != 0 && board[a][b-1] == 'O') {s1.push(a); s2.push(b-1); board[a][b-1] = 'B';}
            else if (b != column - 1 && board[a][b+1] == 'O') {s1.push(a); s2.push(b+1); board[a][b+1] = 'B';}
            else {
                s1.pop(); s2.pop();
            }
        }
    }
private:
    int row, column;
    int a, b;
    stack<int> s1;
    stack<int> s2;
};
