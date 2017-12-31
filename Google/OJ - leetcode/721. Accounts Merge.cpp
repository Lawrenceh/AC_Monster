/* Union Find solution! */
/* TBA */

/* dfs solution */
class Solution {
public:
    void dfs(vector<vector<string> > &accounts, int curr, vector<bool> &visited, unordered_map<string, vector<int> > &m, unordered_set<string> &res) {
        if (curr == accounts.size()) return;
        if (visited[curr]) return;
        visited[curr] = true;
        for (int i = 1; i < accounts[curr].size(); i ++) {
            res.insert(accounts[curr][i]);
            for (auto level: m[accounts[curr][i]]) {
                dfs(accounts, level, visited, m, res);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // dfs solution
        vector<bool> visited(accounts.size(), false);
        unordered_map<string, vector<int> > m;
        vector<vector<string> > ans;
        // generate mapping
        for (int i = 0; i < accounts.size(); i ++) {
            for (int j = 1; j < accounts[i].size(); j ++) {
                m[accounts[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < accounts.size(); i ++) {
            unordered_set<string> res;
            vector<string> v;
            dfs(accounts, i, visited, m, res);
            if (res.size() == 0) continue; // when one is already visited, we skip adding that to final ans vector
            v.push_back(accounts[i][0]);
            for (auto e: res) {
                v.push_back(e);
            }
            sort(v.begin(), v.end()); // emails in sorted order
            ans.push_back(v);
        }
        return ans;
    }
};
