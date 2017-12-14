class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        if (s.length() != t.length()) return false;
        for (auto c: s) {
            m[c] ++;
        }
        for (auto c: t) {
            if (m.find(c) == m.end() || m[c] == 0)
                return false;
            m[c] --;
        }
        return true;
    }
};
