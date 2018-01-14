class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (int i = 0; i < t.length(); i ++) m[t[i]] ++;
        int begin = 0, end = 0, cnt = t.length(); int head = 0, l = INT_MAX;
        while (end < s.length()) {
            if (m.find(s[end]) != m.end()) if (m[s[end]]-- > 0) cnt --;
            end ++;
            while (!cnt) {
                if (end - begin < l) {
                    l = end - begin;
                    head = begin;
                }
                if (m.find(s[begin]) != m.end()) if (m[s[begin]]++ == 0) cnt ++;
                begin ++;
            }
        }
        return (l == INT_MAX) ? "" : s.substr(head, l);
    }
};
