class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* always increment j to put that value at the right position in [0, j], need to do check
        int i = -1, k = -1, j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                i ++;
                k ++;
                swap(nums[k], nums[i]);
                if (k != j) swap(nums[j], nums[i]);
            } else if (nums[j] == 1) {
                k ++;
                swap(nums[j], nums[k]);
            }
            j ++;
        }
        */
        /* consider i as either the left bound of mid section, n as the right, or 
        i as the location the next 0 should go to, and n as the place for 2. */
        int i = 0, n = nums.size() - 1, j = 0;
        while (j <= n) {
            if (nums[j] == 0) {
                swap(nums[j++], nums[i++]);
            } else if (nums[j] == 1) {
                j++;
            } else {
                swap(nums[j], nums[n--]);   
            }
        }
    }
};
