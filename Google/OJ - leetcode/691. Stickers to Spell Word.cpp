/* dfs + dp memoization pruning */

/* The idea is to apply each sticker on the target string once, and search recursively on the next updated target string */
class Solution {
public:
    int search(vector<vector<int> > &v, string s, unordered_map<string, int> &dp) {
        if (dp.count(s)) return dp[s];
        vector<int> vs(26, 0);
        int m = INT_MAX;
        for (auto c: s) vs[c - 'a'] ++;
        for (int i = 0; i < v.size(); i ++) {
            if (v[i][s[0] - 'a'] == 0) continue; // from 369ms to 32ms
            string ts;
            for (int j = 0; j < 26; j ++) {
                if (vs[j] > v[i][j]) ts += string(vs[j] - v[i][j], 'a' + j);
            }
            if (ts == s) continue; // avoid self-loop
            int res = search(v, ts, dp);
            if (res != -1) m = min(m, res + 1);
        }
        dp[s] = (m == INT_MAX ? -1 : m);
        return dp[s];
    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int> > v(stickers.size(), vector<int>(26, 0));
        for (int i = 0; i < stickers.size(); i ++) {
            for (auto c: stickers[i]) {
                v[i][c - 'a'] ++;
            }
        }
        // memoization
        unordered_map<string, int> dp;
        dp[""] = 0;
        return search(v, target, dp);
    }
};
