class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        if (nums.empty()) return false;
        for (int i = 0; i < nums.size(); i ++) {
            if (m.count(nums[i])) {
                if (i - m[nums[i]] <= k) return true;
                else m[nums[i]] = i;
            } else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
