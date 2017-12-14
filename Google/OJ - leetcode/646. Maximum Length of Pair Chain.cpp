/* greedy - sorting by the end of the interval */
bool comparePairs(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0, end = 0;
        sort(pairs.begin(), pairs.end(), comparePairs);
        for (int i = 0; i < pairs.size(); i ++) {
            if (i == 0) {
                ans ++;
                end = pairs[i][1];
            }
            else {
                if (pairs[i][0] > end) {
                    ans ++;
                    end = pairs[i][1];
                }
            }
        }
        return ans;
    }
};


/* dp - sorting by start, and then treat it as the LIS problem */
bool comparePairs(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comparePairs);
        int n = pairs.size();
        if (n == 0) return 0;
        int dp[n];
        fill_n(dp, n, 1);
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                } else {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
        }
        return dp[n - 1];
    }
};
