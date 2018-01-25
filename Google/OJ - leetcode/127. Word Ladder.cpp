class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        int l = q.size();
        string ts;
        bool found = false;
        while (!q.empty() && !found) {
            l = q.size();
            for (int k = 0; k < l; k ++) {
                string s = q.front();
                if (s == endWord) {
                    found = true;
                    break;
                }
                q.pop();
                for (int i = 0; i < s.size(); i ++) {
                    for (int j = 0; j < 26; j ++) {
                        ts = s.substr(0, i) + (char)('a' + j) + s.substr(i + 1);
                        if (dict.find(ts) != dict.end()) {
                            dict.erase(ts);
                            q.push(ts);
                        }
                    }
                }
            }
            res ++;
        }
        return found ? res : 0;
    }
};
