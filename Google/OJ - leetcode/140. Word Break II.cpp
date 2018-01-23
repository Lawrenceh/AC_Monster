/* dp */
class Solution {
public:
    bool isWordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size() + 1] = {false};
        dp[0] = true;
        for (int i = 1; i <= s.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (!isWordBreak(s, wordDict)) return res;
        
        unordered_map<int, vector<string> > m;
        vector<string> vs;
        m[0] = vs;
        for (int i = 1; i <= s.size(); i ++) {
            vector<string> vs;
            m[i] = vs;
            for (int j = 0; j < i; j ++) {
                if ((j == 0 || !m[j].empty()) && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    if (j == 0) {
                        m[i].push_back(s.substr(j, i - j));
                    } else {
                        for (auto ms: m[j]) {
                            m[i].push_back(ms + ' ' + s.substr(j, i - j));
                        }    
                    }
                }
            }
        }
        return m[s.size()];
    }
};
