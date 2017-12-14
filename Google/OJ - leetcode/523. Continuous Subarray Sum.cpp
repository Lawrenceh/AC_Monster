/* idea - use hash table to keep up a[i] % k */

/* NOTE: below code is not AC code */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        if (k == 0) {
            for (auto i: nums) {
                if (i != 0) return false;
            }
            return true;
        }
        unordered_set<int> s;
        s.insert(0);
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
            sum %= k;
            if (s.count(sum)) {
                if (s.size() >= 3) return true;
            }
            s.insert(sum);
        }
        if ()
        return false;
    }
};

/* AC code 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};
*/
