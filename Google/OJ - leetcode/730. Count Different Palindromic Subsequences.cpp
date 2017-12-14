/* DP, iterating through character set plus finding x_x pattern sub-problems */
class Solution {
public:
    int dp[1000][1000];
    int div = 1000000007;
    int count(string s, map<int, set<int> >& m, int l, int r) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        long cnt = 0; // long type
        for (int i = 0; i < 26; i ++) {
            if (m[i].empty()) continue;
            auto nl = m[i].lower_bound(l);
            auto nr = m[i].upper_bound(r);
            nr --;
            if (nl == m[i].end() || *nl > r) continue;
            int il = *nl;
            int ir = *nr;
            cnt ++; // unique element
            if (il == ir) continue;
            cnt ++; // "x_x" case, empty "_" + 1
            cnt += count(s, m, il + 1, ir - 1); // all non-empty "x_x" cases
        }
        dp[l][r] = int(cnt % div);
        return dp[l][r];
    }
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        map<int, set<int> > m; // <ascii, positions> pair
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[i][j] = -1;
            }
        }
        // pre-processing: get all indices of chars in the map
        for (int i = 0; i < n; i++) {
            m[int(S[i]) - 'a'].insert(i);
        }
        return count(S, m, 0, n - 1);
    }
};
