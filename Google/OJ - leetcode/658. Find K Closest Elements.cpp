/* binary search */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /* binary search on the starting point of the k consecutive elements */
        int n = arr.size();
        int left = 0, right = n - k; // must be valid right (otherwise [1,2,3,4,5] w/ k = 4, x = 3 would fail)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) { // the key is to find THIS!
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
