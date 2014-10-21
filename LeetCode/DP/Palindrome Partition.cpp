class Solution {
public:
    int minCut(string s) {
        if (s == "" || s.length() == 1) return 0;
        int n = s.length();
        bool pal[n][n];
        int d[n];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                pal[i][j] = false;
        for (int i = n - 1; i >= 0; i --) {
            d[i] = n - 1 - i;
            for (int j = i; j < n; j ++) {
                if (s[i] == s[j]) {
                    if (j < i + 2 || pal[i + 1][j - 1]) {
                        pal[i][j] = true;
                        if (j == n - 1) d[i] = 0;
                        else if (d[j + 1] + 1 < d[i]) {
                            d[i] = d[j + 1] + 1;
                        }
                    }
                }
            }
        }
        return d[0];
    }
};
