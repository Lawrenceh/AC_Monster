// brilliant solution from @MaskRay

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
    public:
        void gameOfLife(vector<vector<int>> &a) {
            int n = a.size();
            if (!n) return;
            int m = a[0].size();
            REP(i, n)
                REP(j, m)
                    if (a[i][j] & 1)
                        REP(d, 8) {
                            int ii = i+((int[]){-1,-1,-1,0,1,1,1,0})[d], jj = j+((int[]){-1,0,1,1,1,0,-1,-1})[d];
                            if (unsigned(ii) < n && unsigned(jj) < m) a[ii][jj] += 2;
                        }
            REP(i, n)
                REP(j, m)
                    a[i][j] = 4 < a[i][j] && a[i][j] < 8;
        }
};

/* another solution - same idea but slightly different (with state represented by lower and higher bits */

public void gameOfLife(int[][] board) {
    if (board == null || board.length == 0) return;
    int m = board.length, n = board[0].length;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int lives = liveNeighbors(board, m, n, i, j);

            // In the beginning, every 2nd bit is 0;
            // So we only need to care about when will the 2nd bit become 1.
            if (board[i][j] == 1 && lives >= 2 && lives <= 3) {  
                board[i][j] = 3; // Make the 2nd bit 1: 01 ---> 11
            }
            if (board[i][j] == 0 && lives == 3) {
                board[i][j] = 2; // Make the 2nd bit 1: 00 ---> 10
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] >>= 1;  // Get the 2nd state.
        }
    }
}

public int liveNeighbors(int[][] board, int m, int n, int i, int j) {
    int lives = 0;
    for (int x = Math.max(i - 1, 0); x <= Math.min(i + 1, m - 1); x++) {
        for (int y = Math.max(j - 1, 0); y <= Math.min(j + 1, n - 1); y++) {
            lives += board[x][y] & 1;
        }
    }
    lives -= board[i][j] & 1;
    return lives;
}
