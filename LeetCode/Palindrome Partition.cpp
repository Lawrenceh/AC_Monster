class Solution {
    vector<vector<string> > res;
    vector<string> row;
public:
    bool check(string s) {
        for (int i = 0; i < s.length() / 2; i ++) {
            if (s[i] != s[s.length() - 1 - i]) return false;
        }
        return true;
    }
    void dfs(string s) {
        if (s.length() == 0) {
            res.push_back(row);
            return;
        }
        for (int i = 1; i <= s.length(); i ++) {
            if (check(s.substr(0, i))) {
                row.push_back(s.substr(0, i));
                dfs(s.substr(i));
                row.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        row.clear();
        dfs(s);
        return res;
    }
};
