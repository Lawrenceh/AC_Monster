bool myfunction (Interval i, Interval j) { return (i.start < j.start); }

class Solution { 
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myfunction);
        vector<Interval> res;
        Interval k;
        if (intervals.empty()) return res;
        k = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > k.end) {
                res.push_back(k);
                k = intervals[i];
                continue;
            }
            k.end = max(intervals[i].end, k.end);
        }
        res.push_back(k);
        return res;
    }
};

// revised solution - using vector.back()
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
};
