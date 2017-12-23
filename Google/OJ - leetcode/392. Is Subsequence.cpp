class Solution {
public:
    // Follow up question: use a hash table storing list of postions of that character and do binary search
    bool isSubsequence(string s, string t) { 
        int ps = 0, pt = 0;
        while (ps < s.size()) {
            if (pt == t.size()) return false;
            if (s[ps] == t[pt]) {
                ps ++;
                pt ++;
            } else {
                pt ++;
            }
        }
        return true;
    }
};
