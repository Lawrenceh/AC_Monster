class Solution {
public:
    void dfs(vector<int> v, int n, int pos) {
        if (pos == n) {
            res.push_back(v);
            return;
        }
        for (int i = pos; i < n; i ++) {
            swap(v[pos], v[i]);
            dfs(v, n, pos + 1);
            swap(v[pos], v[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        res.clear();   
        dfs(num, num.size(), 0);
        return res;
    }
private:
    vector<vector<int> > res;
};
