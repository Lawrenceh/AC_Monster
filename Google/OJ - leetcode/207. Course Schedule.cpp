/* TOPOLOGICAL SORTING */
DFS(G,V):
1. Mark V as "being explored"
2. For every vertex K belonging to Adj.(V)
   -- If K is not explored, 
      -- Call DFS(G,K)
   -- else if K is "being explored" (not "fully explored")
      -- then there is a cycle
3. Mark V as "fully explored" 


/* dfs: topological sorting */
/* NOTE: see problem 210 for problem ii */
class Solution {
public:
    bool solvable = true;
    vector<bool> visited; // being explored
    vector<bool> explored; // fully explored
    unordered_map<int, vector<int> > m;
    void dfs(int node) {
        if (!solvable) return; // cycle already found
        visited[node] = true; // temporary mark
        for (auto i: m[node]) {
            if (explored[i]) continue;
            if (visited[i]) { // cycle detected
                solvable = false;
                return;
            }
            dfs(i);
        }
        visited[node] = false; // remove temporary mark (might not be necessary)
        explored[node] = true; // permanent mark
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // topological sorting
        visited.resize(numCourses, false);
        explored.resize(numCourses, false);
        for (auto p: prerequisites) {
            m[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; i ++) {
            if (!explored[i]) dfs(i);
        }
        return solvable;
    }
};
