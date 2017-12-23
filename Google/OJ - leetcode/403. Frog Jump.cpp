/* dfs + memorization */
/* NOTE: search via next values not iterating through k - 1, k, k + 1 */
class Solution {
public:
    map<pair<int, int>, bool> m; // using unordered_map requires a hash() for pair
    bool dfs(vector<int> &v, int pos, int k) {
        pair<int, int> p = make_pair(pos, k);
        if (m.count(p)) return m[p];
        for (int i = pos + 1; i < v.size(); i ++) {
            int gap = v[i] - v[pos];
            if (gap < k - 1) continue;
            if (gap > k + 1) {
                m[p] = false;
                return false; // sorted ascending order
            }
            if (dfs(v, i, gap)) {
                m[p] = true;
                return true;
            }
        }
        m[p] = (pos == v.size() - 1);
        return m[p];
    }
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
};
