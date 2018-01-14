class Solution {
public:
    int lengthOfLongestSubstring(string s) { // could be optimized using a map instead of a set to skip some indices
        if (s.empty()) return 0;
        unordered_set<char> us;
        int m = 0, i = 0, j = 0;
        while (j < s.size()) {
            if (us.find(s[j]) == us.end()) {
                us.insert(s[j++]);
            } else {
                if (us.find(s[i]) != us.end()) {
                    us.erase(s[i++]);
                } else {
                    i ++;
                }
            }
            m = max(m, j - i);
        }
        m = max(m, j - i); // need to update after last iteration if j keeps increasing at the end
        return m;
    }
};
