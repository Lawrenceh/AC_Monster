class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0 || s.length() == 1) return 0;
        int n = s.length();
        int a[n];
        int maxlength = 0;
        memset(a, 0, sizeof(a));
        for (int i = 1; i < n; i ++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    a[i] = (i >= 2) ? a[i - 2] + 2 : 2;
                    maxlength = max(a[i], maxlength);
                } else { // s[i - 1] == ')'
                    int l = a[i - 1];
                    if (s[i - 1 - l] == '(') { // important: do not miss the last part!
                        a[i] = a[i - 1] + 2 + (i - 2 - l >= 0 ? a[i - 2 - l] : 0);
                        maxlength = max(a[i], maxlength);
                    }
                }
            }
        }
        return maxlength;
    }
};
