class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> m; // reverse mapping
        for (int i = 0; i < s.size(); i ++) {
            if (m.count(s[i])) {
                if (m[s[i]] != t[i]) return false;
            } else {
            
                m[s[i]] = t[i];
            }
        }
        m.clear();
        for (int i = 0; i < s.size(); i ++) {
            if (m.count(t[i])) {
                if (m[t[i]] != s[i]) return false;
            } else {
            
                m[t[i]] = s[i];
            }
        }
        return true;
    }
};

/* another solution */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
