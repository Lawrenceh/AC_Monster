/* binary search */
class Solution {
public:
    /* KEY */
    /* if the first member is less than the last member, theres no rotation in the array! */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            // now there's rotation and the min value must not be the first element!
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) { // must catch mid == left in 2 element cases
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

/* better solution covering duplicates */
/* compare mid against the right most element */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right --;
            }
        }
        return nums[left];
    }

};
