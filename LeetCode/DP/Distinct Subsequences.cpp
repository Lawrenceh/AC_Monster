class Solution {
public:
    int numDistinct(string S, string T) {
        int sl = S.length(), tl = T.length();
        if (tl == 0) return 1;
        if (sl == 0) return 0;
        int a[tl + 1];
        memset(a, 0, sizeof(a));
        a[0] = 1;
        for (int i = 0; i < sl; i ++) {
            for (int j = tl; j >= 1; j --) {
                if (S[i] == T[j - 1]) a[j] += a[j - 1];   
            }
        }
        return a[tl];
    }
};
