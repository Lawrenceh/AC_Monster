class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m; // mapping from location of edges towards its # of crossing edges (not crossing bricks)
        int cnt = 0;
        int sum = 0;
        for (auto brick: wall[0]) sum += brick;
        for (auto row: wall) {
            int length = 0;
            for (auto brick: row) {
                length += brick; // check current cut @length
                if (length == sum) break;// skip the right edges
                m[length] += 1;
                cnt = max(cnt, m[length]);
            }
        }
        return wall.size() - cnt;
    }
};
