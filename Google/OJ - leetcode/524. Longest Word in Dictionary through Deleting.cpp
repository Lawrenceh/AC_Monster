class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (int i = 0; i < d.size(); i ++) {
            int j = 0, k = 0;
            while (k != d[i].size() && j != s.size()) {
                if (s[j] == d[i][k]) {
                    j ++;
                    k ++;
                } else {
                    j ++;
                }    
            }
            if (k == d[i].size()) { // match
                if (ans.size() < d[i].size()) ans = d[i];
                else if (ans.size() == d[i].size() && ans > d[i]) ans = d[i];
            }
        }
        return ans;
    }
};
