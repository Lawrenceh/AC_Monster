class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> us(nums1.begin(), nums1.end());
        for (auto i: nums2) {
            if (us.count(i)) {
                res.push_back(i);
                us.erase(i);
            }
        }
        return res;
    }
};
