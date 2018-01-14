/* disjoint set solution */

class Solution {
public:
    /* disjoint set union find solution */
    // find-set
    vector<int> father;
    vector<int> rank;
    int findSet(int x) {
        while (x != father[x]) {
            x = father[x];
        }
        return x;
    }
    void unionSet(int x, int y) { // update root father information not current node
        x = findSet(x);
        y = findSet(y);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            father[y] = x;
        } else {
            if (rank[x] == rank[y]) {
                rank[y] ++;
            }
            father[x] = y;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        // pre-process
        father.resize(n, 0);
        rank.resize(n, 0);
        // make-set
        for (int i = 0; i < n; i ++) father[i] = i;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (M[i][j] == 1) {
                    unionSet(i, j);
                }
            }
        }
        unordered_set<int> v; // already seen root of all disjoint sets
        for (int i = 0; i < n; i ++) {
            v.insert(findSet(i));
        }
        return v.size();
    }
    /* below is dfs solution 
    void dfs(vector<vector<int> > &vs, bool *visited, int i) {
        for (int j = 0; j < vs.size(); j ++) {
            if (vs[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(vs, visited, j);
            }
        }
    }   
    int findCircleNum(vector<vector<int>>& M) {
        int cnt = 0;
        int n = M.size();
        bool visited[n] = {false};
        for (int i = 0; i < M.size(); i ++) {
            if (!visited[i]) {
                dfs(M, visited, i); // mark all circle members via DFS
                cnt ++;
            }
        }
        return cnt;
    }
    */
};

/* dfs */
class Solution {
public:
    void dfs(vector<vector<int> > &vs, bool *visited, int i) {
        for (int j = 0; j < vs.size(); j ++) {
            if (vs[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(vs, visited, j);
            }
        }
    }   
    int findCircleNum(vector<vector<int>>& M) {
        int cnt = 0;
        int n = M.size();
        bool visited[n] = {false};
        for (int i = 0; i < M.size(); i ++) {
            if (!visited[i]) {
                dfs(M, visited, i); // mark all circle members via DFS
                cnt ++;
            }
        }
        return cnt;
    }
};
