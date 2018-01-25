class Solution {
public:
    bool canJump(vector<int>& nums) {
        int prev = -1;
        if (nums.empty()) return true;
        int n = nums.size();
        if (n == 1) return true;
        int i = 0;
        while (prev != i) {
            int local = INT_MIN;
            if (prev == -1) prev = 0;
            for (int j = prev; j <= i; j ++) {
                local = max(nums[j] + j, local);
            }
            prev = i;
            i = local;
            if (i >= n - 1) return true;
        }
        return false;
        // below is concise solution
        /*
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + A[i], reach);
        return i == n;
        */
    }
};
