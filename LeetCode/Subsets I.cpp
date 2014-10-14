class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};

class Solution {
    vector<vector<int> > res;
    vector<int> vi;
public:
    void dfs(vector<int> S, int n, int pos) {
        // pos: only the index (not the # of elements in the set!)
        if (pos == n) {
            res.push_back(vi);
            return;
        }
        vi.push_back(S[pos]);
        dfs(S, n, pos + 1);
        vi.pop_back();
        dfs(S, n, pos + 1);
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vi.clear(); res.clear();
        sort(S.begin(), S.end());
        dfs(S, S.size(), 0);
        return res;
    }
};
