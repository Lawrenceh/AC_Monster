class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // find median (partially sorted property is not required)
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // virtual indexing
        #define A(i) nums[(1+2*(i)) % (n|1)]

        // swapping on the virtual indices elements (positioning that value to the right place every iteration)
        int left = 0, right = n - 1, i = 0;
        while (i <= right) {
            if (A(i) < mid) {
                swap(A(right--), A(i));
            } else if (A(i) > mid) {
                swap(A(left++), A(i++)); // we can increment i because left marks the ones > mid
            } else {
                i++;
            }
        }
    }
};
