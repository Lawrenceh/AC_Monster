class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        unordered_set<int> us;
        for (auto n: nums) 
            if (us.count(n)) return true;
            else us.insert(n);
        return false;
    }
};
