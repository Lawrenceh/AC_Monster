/* keep trying with latest * representing for 0, 1, 2, etc. digits, with record of previous positions */
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int prevp = -1, prevs = -1;
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                i ++;
                j ++;
            } else if (p[j] == '*') {
                prevp = j ++;
                prevs = i;
            } else if (prevp != -1) {
                j = prevp + 1;
                i = ++ prevs;
            } else {
                return false;
            }
        }
        while (j < p.size() && p[j] == '*') j ++;
        return (j == p.size());
    }
};

/* dp */
P[i][j] = P[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'), if p[j - 1] != '*';
P[i][j] = P[i][j - 1] || P[i - 1][j], if p[j - 1] == '*'.
