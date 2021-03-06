class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0 || n == 0) return max(m, n);
        int a[m + 1][n + 1];
        for (int i = 0; i <= m; i ++)
            for (int j = 0; j <= n; j ++)
                a[i][j] = 0;
        for (int i = 0; i <= m; i ++) a[i][0] = i;
        for (int j = 0; j <= n; j ++) a[0][j] = j;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                a[i][j] = min(min(a[i - 1][j] + 1, a[i][j - 1] + 1), (word1[i - 1] == word2[j - 1] ? a[i - 1][j - 1] : a[i - 1][j - 1] + 1));
            }
        }
        return a[m][n];
    }
};
