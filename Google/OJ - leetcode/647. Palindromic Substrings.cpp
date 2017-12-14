/* dp */
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        if (n == 0) return 0;
        bool dp[n][n]; // dp[i][j]: if s[i, j] starting from i to j, is palindromic
        for (int i = n - 1; i >= 0; i --) { // n - 1 done at init
            for (int j = i; j < n; j ++) {
                if (s[i] == s[j]) {
                    if (j - i + 1 > 2) {
                        dp[i][j] = dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = true;
                    }
                } else {
                    dp[i][j] = false;
                }
                if (dp[i][j]) ans ++;
            }
        }
        return ans;
    }
};

/* Another idea: extending strings from each center */
class Solution {
public:
    int cnt;
    int countSubstrings(string s) {
        cnt = 0;
        // extend string from center, both odd and even cases
        for (int i = 0; i < s.size(); i ++) {
            extendString(s, i, i); // odd
            extendString(s, i, i + 1); // even
        }
        return cnt;
    }
    void extendString(string s, int left, int right) {
        while (left >= 0 && right <= s.size() -1 && s[left] == s[right]) {
            cnt ++;
            left --;
            right ++;
        }
    }
};
