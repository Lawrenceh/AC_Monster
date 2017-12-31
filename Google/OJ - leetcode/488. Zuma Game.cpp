/* dfs ZUMA: check removing duplicates one/block by one/block, see if there are enough balls at hand */
/* dfs only needs 1) remaining string after removal 2) current available balls at hand */
class Solution {
public:
    int TH = 6;
    int dfs(string s, vector<int> &v) {
        s = removeConsecutive(s);
        int cnt = TH; // number of balls in hand is limited to 5 at max
        if (s == "#") return 0;
        int need = 0;
        for (int i = 0, j = 0; j < s.size(); j ++) {
            // check inserting ball to delete ball @i and followings
            if (s[i] == s[j]) continue;
            need = 3 - (j - i);
            if (v[s[i] - 'A'] >= need) {
                v[s[i] - 'A'] -= need;
                cnt = min(cnt, need + dfs(s.substr(0, i) + s.substr(j, s.size() - j), v));
                v[s[i] - 'A'] += need;
            }
            i = j; // check "next" color ball
        }
        return cnt;
    }
    string removeConsecutive(string s) {
        for (int i = 0, j = 0; j < s.size(); j ++) {
            // check inserting ball to delete ball @i and followings
            if (s[i] == s[j]) continue;
            if (j - i >= 3) {
                return removeConsecutive(s.substr(0, i) + s.substr(j, s.size() - j));
            }
            i = j;
        }
        return s;
    }
    int findMinStep(string board, string hand) {
        vector<int> v(26, 0); // availability
        for (auto c: hand) v[c - 'A'] ++;
        int cnt = dfs(board + "#", v); // adding '#' special character to make for loop termination condition easier
        return (cnt == TH) ? -1 : cnt;
    }
};
