class Solution {
public:
    int trap(vector<int>& height) {
        // brute-force find max left and right
        // dp
        // stack solution to track left max (top) - see previous submission
        
        // here is the O(1) solution - optimized dp
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > left_max) left_max = height[left];
                else ans += left_max - height[left];
                left ++;
            } else {
                if (height[right] > right_max) right_max = height[right];
                else ans += right_max - height[right];
                right --;
            }
        }
        return ans;
    }
};
