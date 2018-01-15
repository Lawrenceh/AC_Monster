class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, int>> pq;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i ++) m[s[i]] ++;
        for (auto em : m) {
            pq.push({em.second, em.first});
        }
        string rs;
        while (!pq.empty()) {
            int t = pq.top().first;
            char c = pq.top().second;
            while (t-- != 0) rs.push_back(c);
            pq.pop();
        }
        return rs;
    }
};
