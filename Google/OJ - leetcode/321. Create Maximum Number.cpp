/* dp idea + stack container for solving sub-problem */
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        for (int i = 0; i <= min(k, m); i ++) {
            if (k - i > n) continue;
            ans = max(ans, merge(maxNumber(nums1, i), maxNumber(nums2, k - i)));
        }
        return ans;
    }
    vector<int> maxNumber(vector<int> nums, int k) {
        int drop = nums.size() - k;
        vector<int> out;
        for (int num : nums) {
            while (drop && out.size() && out.back() < num) {
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> out;
        while (a.size() + b.size()) {
            vector<int> &v = (a > b) ? a : b;
            out.push_back(v[0]);
            v.erase(v.begin());
        }
        return out;
    }
};
