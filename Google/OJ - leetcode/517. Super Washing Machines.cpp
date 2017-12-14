/* calculate the max of the machine with most necessary ops */
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum[n + 1];
        fill_n(sum, n + 1, 0);
        for (int i = 0; i < n; i ++) {
            sum[i + 1] = sum[i] + machines[i];
        }
        if (sum[n] % n) return -1;
        int avg = sum[n] / n;
        int ans = 0, left = 0, right = 0;
        for (int i = 0; i < n; i ++) { // left, right: required - current
            left = avg * i - sum[i];
            right = avg * (n - i - 1) - (sum[n] - sum[i + 1]);
            if (left > 0 && right > 0) {
                ans = max(ans, left + right);
            } else if (left < 0 && right < 0) {
                ans = max(ans, max(-left, -right));
            } else {
                ans = max(ans, max(abs(left), abs(right)));
            }
        }
        return ans;
    }
};
