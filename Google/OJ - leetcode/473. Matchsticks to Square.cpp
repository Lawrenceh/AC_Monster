/* dfs: maintain size of 4 sides[] array to keep track of current stage sides length's, and insert current index value in nums to one of them */
class Solution {
public:
    bool dfs(vector<int>& nums, vector<int>& sides, int m, int index) {
        if (index == nums.size()) {
            if (sides[0] == m && sides[1] == m && sides[2] == m && sides[3] == m) return true;
            else return false;
        }
        for (int i = 0; i < 4; i ++) {
            if (sides[i] + nums[index] > m) continue;
            
            /* below is to check if there's same length side dfs'ed before, if so we skip to the next edge */
            int j = i;
            while (--j >= 0) {
                if (sides[j] == sides[i]) break;
            }
            if (j != -1) continue;
            
            // add current matchstick to that side
            sides[i] += nums[index];
            if (dfs(nums, sides, m, index+1)) return true;
            sides[i] -= nums[index];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) sum += nums[i];
        int mv = sum / 4;
        vector<int> sides(4, 0);
        return dfs(nums, sides, mv, 0);
    }
};
