/* dp - alphabetic dp array */
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int dp[26];
        fill_n(dp, 26, 0);
        int maxl = 0;
        for (int i = 0; i < p.size(); i ++) {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)) {
                maxl ++;
            } else {
                maxl = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], maxl);
        }
        int ans = 0;
        for (int i = 0; i < 26; i ++) ans += dp[i];
        return ans;
    }
};
