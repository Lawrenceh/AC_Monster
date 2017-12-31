/* BINARY SEARCH KEY POINTS SUMMARY:
1) check 2 element case infinity loop and two boundary cases
2) when value not found, we might need to see if the final element is compared or not (when left = -1 or right = n comes into play)
*/

/* find the first element which is equal or larger than target */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // find the first element which is equal or larger than target
        int n = nums.size();
        if (n == 0) return 0;
        int left = 0, right = n; // right = n - 1 is WRONG! We should use right = n in this problem! (the last element is not compared!)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};


/* find the first element which is equal or smaller than target */

int main() {
    vector<int> nums = {3,5,6,8};
    int target = 2;
    int n = nums.size();
    if (n == 0) return 0;
    int left = -1, right = n - 1;

    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    cout << left << endl;
}
