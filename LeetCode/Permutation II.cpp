class Solution {
    vector<vector<int> > res;
public:
    void dfs(vector<int> v, int n, int pos) {
        if (n == pos) {
            res.push_back(v);
            return;
        }
        sort(v.begin() + pos, v.end());
        for (int i = pos; i < n; i ++) {
            if (i == pos || (i != pos && v[i] != v[pos])) {
                swap(v[i], v[pos]);
                dfs(v, n, pos + 1);
                swap(v[i], v[pos]);
                while (i < n - 1 && v[i] == v[i+1]) i++;  
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        res.clear();
        sort(num.begin(), num.end());
        dfs(num, num.size(), 0);
        return res;
    }
};
