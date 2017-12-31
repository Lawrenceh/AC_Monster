/* dfs: pick two numbers first, then do a type of op, push result back, then go another dfs(), which ends with only one value left */
class Solution {
public:
    double eps = 0.001;
    bool dfs(vector<double> &v) {
        if (v.size() == 1) {
            if (abs(v[0] - 24.0) < eps) return true;
            else return false;
        }
        for (int i = 0; i < v.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                // pick two numbers first, from pos i and j
                vector<double> next; // all possible result from first two number operations
                double p1 = v[i];
                double p2 = v[j];
                next.push_back(p1 + p2);
                next.push_back(p1 - p2);
                next.push_back(p2 - p1);
                next.push_back(p1 * p2);
                if (abs(p1) > eps) next.push_back(p2 / p1);
                if (abs(p2) > eps) next.push_back(p1 / p2);
                // depth-first search
                v.erase(v.begin() + i);
                v.erase(v.begin() + j);
                for (auto n: next) {
                    v.push_back(n);
                    if (dfs(v)) return true;
                    v.pop_back();
                }
                v.insert(v.begin() + j, p2);
                v.insert(v.begin() + i, p1);
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> v(nums.begin(), nums.end());
        return dfs(v);
    }
};
