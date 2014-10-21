class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s), n = strlen(p);
        bool a[m + 1][n + 1];
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                a[i][j] = false;
            }
        }
        a[0][0] = true;
        for (int i = 1; i <= m; i ++) {
            a[i][0] = false;
        }
        for (int j = 1; j <= n; j ++) {
            a[0][j] = (p[j - 1] == '*' && j >= 2 && a[0][j - 2]);
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                a[i][j] = ((a[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.' 
                || (j >= 2 && s[i - 1] == p[j - 2] && p[j - 1] == '*') || (j >= 2 && p[j - 2] == '.' && p[j - 1] == '*')))
                    || (a[i - 1][j] && p[j - 1] == '*' && j >= 2 && (p[j - 2] == s[i - 1] || p[j - 2] == '.'))
                    || (a[i][j - 1] && p[j - 1] == '*')
                    || (j >= 2 && a[i][j - 2] && p[j - 1] == '*'));
            }
        }
        return a[m][n];
    }
};
