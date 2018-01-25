class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, e = 0, m = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            m = max(m, nums[i] + i);
            if (i == e) {
                cnt ++;
                e = m;
            }
        }
        return cnt;
    }
};
