class Solution {
public:
    vector<vector<string> > res;
    vector<string> v;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        dict.erase(beginWord);
        unordered_map<string, vector<string> > m; // neighbors
        bfs(beginWord, endWord, dict, m);
        dfs(beginWord, endWord, m);
        return res;
    }
    void dfs(string beginWord, string endWord, unordered_map<string, vector<string> > &m) {
        if (beginWord == endWord) {
            v.push_back(endWord);
            res.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(beginWord);
        for (auto w: m[beginWord]) {
            dfs(w, endWord, m);
        }
        v.pop_back();
    }
    void bfs(string beginWord, string endWord, unordered_set<string> &dict, unordered_map<string, vector<string> > &m) {
        if (beginWord == endWord) return;
        queue<string> q;
        q.push(beginWord);
        int l = q.size();
        string ts;
        bool found = false;
        while (!q.empty()) {
            l = q.size();
            vector<string> eraseList;
            for (int k = 0; k < l; k ++) {
                string s = q.front();
                q.pop();
                if (s == endWord) {
                    found = true;
                    continue;
                }
                for (int i = 0; i < s.size(); i ++) {
                    for (int j = 0; j < 26; j ++) {
                        ts = s.substr(0, i) + (char)('a' + j) + s.substr(i + 1);
                        if (dict.find(ts) != dict.end()) {
                            m[s].push_back(ts);
                            eraseList.push_back(ts);
                            q.push(ts);
                        }
                    }
                }
            }
            for (auto e: eraseList) dict.erase(e);
            if (found) break;
        }
    }
};
