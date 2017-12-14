/* recursion dfs (optimization needed to avoid TLE) */

/* 1st version (TLE): using a[] to keep track of numbers, duplicate failure search because no difference among 1st~kth bucket */
class Solution {
public:
    bool check(int a[], int k, int target) {
        for (int i = 0; i < k; i ++) {
            if (a[i] != target) return false;
        }
        return true;
    }
    bool dfs(vector<int> &nums, int n, int k, int target, int a[], int pos) {
        if (pos == n) return check(a, k, target);
        for (int i = 0; i < k; i ++) {
            if (a[i] + nums[pos] > target) continue;
            a[i] += nums[pos];
            if (dfs(nums, n, k, target, a, pos + 1)) return true;
            a[i] -= nums[pos];
            if (i == 0 && pos == 0) return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int a[n];
        memset(a, 0, sizeof(int) * n);
        int sum = 0, target = 0;
        for (auto i: nums) {
            sum += i;
        }
        if (sum % k == 0) {
            target = sum / k;
        } else {
            return false;
        }
        return dfs(nums, n, k, target, a, 0);
    }
};

/* 2nd attempt (TLE, but better): no a[], only visited[]. TLE again because we always start from i = 0
 * !In the current subset next value search, previous visited or tried elements should be skipped */
class Solution {
public:
    bool dfs(vector<int> &nums, int n, int curr, int k, int sum, int target, bool visited[]) {
        if (curr == k) return true;
        if (sum > target) return false;
        if (sum == target) {
            if (dfs(nums, n, curr + 1, k, 0, target, visited)) return true;
        }
        for (int i = 0; i < n; i ++) { // every dfs starts from i = 0, could be time-consuming if we have large n
            if (!visited[i]) {
                visited[i] = true;
                if (dfs(nums, n, curr, k, sum + nums[i], target, visited)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, target = 0;
        for (auto i: nums) {
            sum += i;
        }
        if (sum % k == 0) {
            target = sum / k;
        } else {
            return false;
        }
        bool visited[n];
        memset(visited, false, sizeof(bool) * n);
        return dfs(nums, n, 0, k, 0, target, visited);
    }
};

/* 3rd attempt (pass but slow, could be optimized too) */
class Solution {
public:
    bool dfs(vector<int> &nums, int n, int idx, int curr, int k, int sum, int target, bool visited[]) {
        if (curr == k) return true;
        if (sum > target) return false;
        if (sum == target) {
            if (dfs(nums, n, 0, curr + 1, k, 0, target, visited)) return true;
        }
        for (int i = idx; i < n; i ++) { // start from the next element from previous search
            if (!visited[i]) {
                visited[i] = true;
                if (dfs(nums, n, idx + 1, curr, k, sum + nums[i], target, visited)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, target = 0;
        for (auto i: nums) {
            sum += i;
        }
        if (sum % k == 0) {
            target = sum / k;
        } else {
            return false;
        }
        bool visited[n];
        memset(visited, false, sizeof(bool) * n);
        return dfs(nums, n, 0, 0, k, 0, target, visited);
    }
};
