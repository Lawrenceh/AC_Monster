class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n, true);
        v[0] = false; v[1] = false;
        for (int i = 2; i <= int(sqrt(n)); i ++) {
            for (int j = 2; i * j < n; j ++) {
                v[i * j] = false;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += (v[i] == true);
        }
        return sum;
    }
};
