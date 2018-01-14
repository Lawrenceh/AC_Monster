/* hash table bucket sort solution O(n)! */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i ++) {
            m[nums[i]] ++;
        }
        /* using buckets (hash table) */
        vector<vector<int> > buckets(nums.size() + 1, vector<int>());
        for (auto i: m) buckets[i.second].push_back(i.first);
        for (int i = buckets.size() - 1; i >= 0; i --) {
            for (auto val: buckets[i]) {
                res.push_back(val);
                if (res.size() == k) return res;
            }
        }
        
        /* heap solution 
        priority_queue<pair<int, int> > pq;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it ++) {
            pq.push({it->second, it->first});
        }
        vector<int> res;
        while (k-- != 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        */
    }
};


/* heap solution */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i ++) {
            m[nums[i]] ++;
        }
        priority_queue<pair<int, int> > pq;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it ++) {
            pq.push({it->second, it->first});
        }
        vector<int> res;
        while (k-- != 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
