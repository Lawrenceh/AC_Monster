class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<int> > m; // mapping from char set to list of idx in the vector
        for (int i = 0; i < strs.size(); i ++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }
        for (auto iter: m) {
            vector<string> v;
            for (auto idx: iter.second) {
                v.push_back(strs[idx]);
            }
            res.push_back(v);
        }
        return res;
    }
};
