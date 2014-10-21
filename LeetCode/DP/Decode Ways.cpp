class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int a[n + 1];
        memset(a, 0, sizeof(a));
        if (s == "") return 0;
        if (s[0] == '0') return 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] < '0' || s[i] > '9') return 0;
        }
        a[0] = 1; a[1] = 1;
        for (int i = 2; i <= n; i ++) {
            int x = s[i - 1] - '0';
            int y = atoi(s.substr(i - 2, 2).c_str());
            a[i] = (x != 0 ? a[i - 1] : 0) + ((y > 9 && y <= 26) ? a[i - 2] : 0);
            if (s[i] == 0) break;
        }
        return a[n];
    }
};
