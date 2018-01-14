class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (s.find(nums[i] - 1) == s.end()) {
                int y = nums[i] + 1;
                while (s.find(y) != s.end()) {
                    y ++;
                }
                res = max(res, y - nums[i]);
            }
        }
        return res;
    }
};
