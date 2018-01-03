/* dijkstra */

/* NOTE: Dijkstra needs additional DECREASE-KEY implementation, below code is using a HACK which is not correct strictly speaking */

/* Example
 * [[1,2,5],[1,3,10],[2,4,2], [2,3,3]], 4, 1 
 * Above input would yield 5 pushes into the queue, while there are in total only 4 nodes.
 */

class mycomparison {
public:
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) const {
        return (lhs.second > rhs.second);
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int ans = 0;
        unordered_map<int, vector<pair<int, int> > > m; // u -> list of outgoing neighbors w/ time
        int d[N + 1] = {0};
        // preprocessing
        for (auto v: times) {
            m[v[0]].push_back(make_pair(v[1], v[2]));
        }
        // initialize all nodes
        for (int i = 1; i <= N; i ++) d[i] = INT_MAX;
        d[K] = 0;
        // pick min and do relaxation on neighbors
        priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> hp;
        hp.push(make_pair(K, 0));
        // for (int i = 1; i <= N; i ++) hp.push(make_pair(i, d[i])); NOTE: push the whole set V into queue is not wrong but makes updating hard
        while (!hp.empty()) {
            auto tp = hp.top();
            hp.pop();
            int u = tp.first;
            int cw = tp.second;
            for (auto node: m[u]) {
                int v = node.first;
                int w = node.second;
                if (cw + w < d[v]) {
                    d[v] = cw + w;
                    hp.push(make_pair(v, d[v])); // Alternatively we choose to push this into the priority queue dynamically!
                    /* UPDATE: this is incorrect strictly speaking! We would push duplicate nodes with different key values into the queue. The right way is to 1) implement a decrease-key operation or 2) use set */
                }
            }
        }
        // summary
        for (int i = 1; i <= N; i ++) {
            if (d[i] == INT_MAX) return -1;
            else ans = max(d[i], ans);
        }
        return ans;
    }
};
