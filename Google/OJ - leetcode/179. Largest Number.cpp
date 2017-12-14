/* w/ lambda function, to_string and stringstream */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {return to_string(a) + to_string(b) > to_string(b) + to_string(a);});
        stringstream ss;
        for (auto i: nums) {
            ss << to_string(i);
        }
        string s = ss.str();
        while (s.length() > 1 && s[0] == '0') {
            s.erase(0, 1);
        }
        return s;
    }
};
