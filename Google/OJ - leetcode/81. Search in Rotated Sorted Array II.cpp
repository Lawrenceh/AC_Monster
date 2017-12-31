/* very interesting solution based on non-duplicate problem i */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
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
        // left is NOI the rotation point in this duplicate allowable problem!
        // find from the very last element same min value, that is the rotation point!
        int rot = left;
        for (int i = n - 1; i >= 0; i --) {
            if (nums[i] != nums[left]) {
                if (i == n - 1) rot = left;
                else rot = i + 1;
                break;
            }
        }
        // search target using mapping
        left = 0; right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mmid = (rot + mid) % n;
            if (nums[mmid] == target) return true;
            else if (nums[mmid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
