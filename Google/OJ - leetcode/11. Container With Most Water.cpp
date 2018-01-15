/* brilliant idea using two pointers O(n) */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        if (height.empty()) return 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) left ++;
            else right --;
        }
        return res;
    }
};
