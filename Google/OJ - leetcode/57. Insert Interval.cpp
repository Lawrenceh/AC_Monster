/* brute force */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        Interval k = newInterval;
        int flag = 0;
        for (int i = 0; i < intervals.size(); i ++) {
            if (flag == 0) {
                if (intervals[i].end < newInterval.start) {
                    res.push_back(intervals[i]);
                    continue;
                }
                if (newInterval.end < intervals[i].start) {
                    res.push_back(newInterval);
                    i --;
                    flag = -1;
                } else {
                    k.start = min(newInterval.start, intervals[i].start);
                    k.end = max(newInterval.end, intervals[i].end);
                    flag = 1;    
                }
            } else if (flag == 1) {
                if (k.end < intervals[i].start) {
                    res.push_back(k);
                    res.push_back(intervals[i]);
                    flag = -1;
                } else {
                    k.end = max(k.end, intervals[i].end);
                }
            } else {
                res.push_back(intervals[i]);
            }
        }
        if (flag != -1) res.push_back(k);
        return res;
    }
};


/* merge intervals */
bool myfunction (Interval i, Interval j) { return (i.start < j.start); }

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myfunction);
        vector<Interval> res;
        if (intervals.empty()) return res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);   
            }
        }
        return res;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), myfunction);
        return merge(intervals);
    }
};


/* updating the res w/ newInterval inited*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res(1, newInterval);
        for (auto i: intervals) {
            Interval k = res.back();
            if (k.end < i.start) {
                res.push_back(i);
            } else if (i.end < k.start) {
                res.back() = i;
                res.push_back(k);
            } else {
                res.back().end = max(k.end, i.end);
                res.back().start = min(k.start, i.start);
            }
        }
        return res;
    }
};

