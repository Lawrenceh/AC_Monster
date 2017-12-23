/* russian roll envelopes dp */
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first;});
        int n = envelopes.size();
        if (n <= 1) return n;
        int dp[n];
        fill_n(dp, n, 1);
        int ans = 1;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (envelopes[i].second > envelopes[j].second && envelopes[i].first > envelopes[j].first) // 2nd condition for same 1st first
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
