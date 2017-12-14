/* given sorted property, do binary search */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1, mid, n = citations.size();
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (citations[mid] == n - mid) return n - mid;
            else if (citations[mid] > n - mid) { // try searching larger h-index
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - right - 1;
    }
};
