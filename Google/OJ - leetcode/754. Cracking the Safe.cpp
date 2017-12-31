/* dfs w/ greedy idea */
class Solution {
public:
    bool dfs(int n, int k, string &s, unordered_set<string> &visited) {
        if (visited.size() == pow(k, n)) return true;
        string current = s.substr(s.size() - n + 1, n - 1);
        for (int i = 0; i < k; i ++) {
            current += to_string(i);
            if (!visited.count(current)) {
                visited.insert(current);
                s += to_string(i);
                if (dfs(n, k, s, visited)) return true;
                else {
                    s.pop_back();
                    visited.erase(current);
                }
            }
        }
        return false;
    }
    string crackSafe(int n, int k) {
        string s(n - 1, '0');
        unordered_set<string> visited;
        dfs(n, k, s, visited);
        return s;
    }
};
