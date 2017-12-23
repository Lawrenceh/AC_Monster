/* dp idea using 3 pointers */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int i, j, k;
        i = j = k = 0;
        for (int w = 1; w < n; w ++) {
            v[w] = min(v[i] * 2, min(v[j] * 3, v[k] * 5));
            if (v[w] == v[i] * 2) i ++;
            if (v[w] == v[j] * 3) j ++;
            if (v[w] == v[k] * 5) k ++;
        }
        return v[n - 1];
    }
};
