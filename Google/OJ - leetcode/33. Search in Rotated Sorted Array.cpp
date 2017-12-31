/* binary search solution using finding min problem solution w/ mapping! */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* using solution in find the min in rotated sorted array problem */
        /* compare mid against the right most element */
        /* after we find the min location, we know rotation steps */
        /* then we find the target using that mapping */
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
        // left is the rotation point
        int rot = left;
        // search target using mapping
        left = 0; right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mmid = (rot + mid) % n;
            if (nums[mmid] == target) return mmid;
            else if (nums[mmid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

/* old, tedious solution */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
