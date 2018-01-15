class Solution {
public:
    int maximumSwap(int num) {
        /* keep record of the largest value's index rightwards */
        string s = to_string(num);
        vector<int> v(s.size(), -1);
        int max_idx = v.size() - 1; // capture the right [most] max
        for (int i = v.size() - 1; i >= 0; i --) {
            if (s[i] > s[max_idx]) max_idx = i; // strictly larger than
            v[i] = max_idx;
        }
        for (int i = 0; i < s.size(); i ++) {
            if (s[v[i]] == s[i]) continue;
            swap(s[i], s[v[i]]);
            break;
        }
        return stoi(s);
    }
};
