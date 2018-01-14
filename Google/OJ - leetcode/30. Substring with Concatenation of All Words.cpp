/* iterate all starting points, and add wl each increment */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = s.length(), n = words.size();
        unordered_map<string, int> count;
        vector<int> v;
        if (n == 0) return v;
        int wl = words[0].length();
        for (int i = 0; i < n; ++i) count[words[i]] ++;
        for (int i = 0; i <= l - n * wl; ++i) {
            unordered_map<string, int> seen;
            int j;
            for (j = 0; j < n; ++j) {
                string ts = s.substr(i + j * wl, wl);
                if (count.find(ts) != count.end()) {
                    seen[ts] ++;
                    if (seen[ts] > count[ts]) break;
                } else {
                    break;
                }
            }
            if (j == n) {
                v.push_back(i);
            }
        }
        return v;
    }
};
