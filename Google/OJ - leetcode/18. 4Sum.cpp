class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j ++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) 
                        do {right --;}
                        while (left < right && nums[right] == nums[right + 1]);
                    else if (sum < target)
                        do {left ++;}
                        while (left < right && nums[left] == nums[left - 1]);
                    else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do {left ++;}
                        while (left < right && nums[left] == nums[left - 1]);
                        do {right --;}
                        while (left < right && nums[right] == nums[right + 1]);
                    }
                }
            }
        }
        return res;
    }
};
