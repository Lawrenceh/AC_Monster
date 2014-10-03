// unordered_map<int, int>
// find(): nearly constant complexity!!
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hm;
        vector<int> res;
        int rest = 0;
        for (int i = 0; i < numbers.size(); i ++) {
            rest = target - numbers[i];
            unordered_map<int, int>::iterator iter = hm.find(rest);
            if (iter != hm.end()) {
                if (iter->second < i) {
                    res.push_back(iter->second + 1);
                    res.push_back(i + 1);
                    return res;
                } else {
                    res.push_back(i + 1);
                    res.push_back(iter->second + 1);
                    return res;
                }
            }
            hm[numbers[i]] = i;
        }
        return res;
    }
};
