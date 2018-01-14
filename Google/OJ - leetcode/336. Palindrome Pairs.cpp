/* naive solution would be O(n*n*...) */
/* using hash table, we could reduce that to O(n*k*k) (second k comes from checking isPalindrome()) */
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > res;
        unordered_map<string, int> m;
        if (words.empty()) return res;
        // preprocess and add reverse of strings to the map
        for (int i = 0; i < words.size(); i ++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            m[key] = i;
        }
        // corner case of empty string ""
        // it is not fully covered below (only half side)
        auto iter = find(words.begin(), words.end(), ""); 
        if (iter != words.end()) {
            for (int i = 0; i < words.size(); i ++) {
                if (i == iter - words.begin()) continue;
                if (isPalindrome(words[i])) {
                    // res.push_back({i, iter - words.begin()}); 1. this is covered below
                    res.push_back({iter - words.begin(), i});
                }
            }
        }
        // main logic
        for (int i = 0; i < words.size(); i ++) {
            for (int j = 0; j < words[i].size(); j ++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                if (isPalindrome(right) && m.count(left) && i != m[left]) { // 2. cover the other direction pair containing ""
                    res.push_back({i, m[left]});
                }
                if (isPalindrome(left) && m.count(right) && i != m[right]) {
                    res.push_back({m[right], i});
                }
            }
        }
        return res;
    }
};
