/* monotone queue */

/* KEY: if we find a bigger number, we don't need previous biggest number because it will be covered by the current one */
/* therefore, we pop the old biggest number and push that in */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            // if current number is larger than queue front, we keep popping
            while (!q.empty() && i - q.back() >= k) q.pop_back();
            while (!q.empty() && nums[i] >= nums[q.front()]) q.pop_front();
            q.push_front(i); // queue's back is the biggest
            if (i >= k - 1) res.push_back(nums[q.back()]);
        }
        return res;
    }
};

/* the other direction, OJ discuss solution */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
            if (q.front() == i - k + 1) q.pop_front();
        }
        return res;
    }
};
