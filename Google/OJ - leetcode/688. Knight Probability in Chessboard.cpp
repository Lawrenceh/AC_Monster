class Solution {
public:
    vector<pair<int, int> > moves = {{1,2},{1,-2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,-1},{-2,1}};
    double knightProbability(int N, int K, int r, int c) {
        double dp[N][N];
        double t[N][N];
        // step 0
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                dp[i][j] = 1.0; // init with 1's
                t[i][j] = 0.0; // init with 0's
            }
        }
        // step 1 ~ K
        for (int step = 1; step <= K; step ++) {
            for (int i = 0; i < N; i ++) {
                for (int j = 0; j < N; j ++) {
                    for (int d = 0; d < moves.size(); d ++) {
                        int ii = moves[d].first + i, jj = moves[d].second + j;
                        if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
                        t[ii][jj] += 0.125 * dp[i][j];
                    }
                }
            }
            // update dp array from t
            for (int i = 0; i < N; i ++) {
                for (int j = 0; j < N; j ++) {
                    dp[i][j] = t[i][j];
                    t[i][j] = 0.0; // when each step is finished, reset the t
                }
            }
        }
        return dp[r][c];
    }
};
