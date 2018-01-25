class Solution {
public:
    void dfs(int n, vector<char>& d, vector<string>& res, string& s, int cnt, int k) {
        if (cnt > n || cnt < 0) return;
        if (k == 2 * n) {
            if (cnt == 0) res.push_back(s);
            return;
        }
        for (auto c: d) {
            s.push_back(c);
            dfs(n, d, res, s, (c == '(') ? cnt + 1 : cnt - 1, k + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int cnt = 0;
        vector<string> res;
        string s;
        vector<char> vd = {'(', ')'};
        dfs(n, vd, res, s, cnt, 0);
        return res;
    }
};
