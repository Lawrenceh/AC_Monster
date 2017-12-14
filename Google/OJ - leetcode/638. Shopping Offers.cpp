/* dfs */
class Solution {
public:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int cost = 0;
        for (int i = 0; i < n; i ++) {
            cost += price[i] * needs[i];
        }
        int i;
        for (auto s: special) {
            vector<int> v(needs); // refresh current needs for each offer
            for (i = 0; i < n; i ++) {
                if (s[i] > v[i]) break;
                v[i] -= s[i];
            }
            if (i == n) {
                cost = min(cost, s[n] + dfs(price, special, v));
            }
        }
        return cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};

/* Optimization with memorization */

/* NOTE: vector cannot be used as key for unordered_map. __hash__() implementation needed!
 * On the other hand, for map it is fine because there is built-in cmp in std::vector.
 */
class Solution {
public:
    map<vector<int>, int> m; // map for dfs memorization 
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int> &m) {
        if (m.count(needs)) return m[needs];
        int n = price.size();
        int cost = 0;
        for (int i = 0; i < n; i ++) {
            cost += price[i] * needs[i];
        }
        int i;
        for (auto s: special) {
            vector<int> v(needs); // refresh current needs for each offer
            for (i = 0; i < n; i ++) {
                if (s[i] > v[i]) break;
                v[i] -= s[i];
            }
            if (i == n) {
                cost = min(cost, s[n] + dfs(price, special, v, m));
            }
        }
        m[needs] = cost;
        return cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs, m);
    }
};
