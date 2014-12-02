class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // no duplicates case (if does exist, ignore the extra ones)
        unordered_set<int> s;
        s.clear();
        if (num.size() == 0 || num.size() == 1) return num.size();
        for (int i = 0; i < num.size(); i ++) {
            s.insert(num[i]);
        }
        int l = 1;
        int begin, end;
        for (int i = 0; i < num.size(); i ++) {
            if (s.find(num[i]) != s.end()) {
                begin = num[i] - 1;
                end = num[i] + 1;
                s.erase(num[i]);
                while (s.find(begin) != s.end()) {
                    s.erase(begin);
                    begin --;
                }
                while (s.find(end) != s.end()) {
                    s.erase(end);
                    end ++;
                }
                l = max(l, end - begin - 1);
            }
        }
        return l;
    }
};
