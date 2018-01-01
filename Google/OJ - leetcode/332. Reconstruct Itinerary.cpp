/* We can 1) record node when it's first visted 2) when it's done. The second one is used in toposort. When calculating Eulerian path, we try to iterate all possible edges first, when all these are done, we add that to the route. i.e. we record the finish time of nodes. */

/* dfs: Eulerian Path */
class Solution {
public:
    vector<string> route;
    // unordered_map<string, set<string> > m; NOTE: this is correct when there's only one directed edge per source and target
    // when there's multiple edges per source and target, we need multiset to allow duplicates
    unordered_map<string, multiset<string> > m;
    void dfs(string s) { // Eulerian path: dfs w/ adding node to route when it is finished finally
        string next;
        while (m[s].size() != 0) {
            next = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(next);
        }
        // when there's no other possible paths, this node is finished, add it to route
        route.push_back(s);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto p: tickets) {
            m[p.first].insert(p.second);
        }
        dfs("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};
