/* Segment trees on RMQ problem */
root: [i, j]
children: left [i, (i + j) / 2], right [(i + j) / 2 + 1, j]

height: h = floor(logN) + 1

We need an array M[1, 2*2^h] where M[i] holds min value position in the interval assigned to node i.

/* array M initialized with -1 */
void initialize(int node, int b, int e, int M[MAXIND], int A[MAXN], int N) {
    if (b == e) {
        M[node] = b;
    } else {
        initialize(2 * node, b, (b + e) / 2, M, A, N);
        initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
        if (A[M[2 * node]] <= A[M[2 * node + 1]]) M[node] = M[2 * node];
        else M[node] = M[2 * node + 1]; 
    }
} 

/* query on [i, j], starting with first node (root) */
int query(int node, int b, int e, int M[MAXIND], int A[MAXN], int i, int j) {
    int p1, p2;

    //if the current interval doesn't intersect the query interval, return -1
    if (i > e || j < b) return -1;

    //if the current interval is included in the query interval, return M[node]
    if (b >= i && e <= j) return M[node]; // return the part in current node

    p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
    p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (A[p1] <= A[p2]) return p1;
    else return p2;
}

Complexity: <O(N), O(logN)> (preprocessing time, query time)


Example: leetcode 307


class NumArray {
public:
    vector<int> v;
    int *a;
    int n;
    void buildTree(int node, int begin, int end) {
        if (begin == end) {
            a[node] = v[begin];
        } else {
            buildTree(node * 2, begin, (begin + end) / 2);
            buildTree(node * 2 + 1, (begin + end) / 2 + 1, end);
            a[node] = a[node * 2] + a[node * 2 + 1];
        }
    }
    NumArray(vector<int> nums) {
        if (nums.empty()) return;
        v = nums;
        n = nums.size();
        a = new int[n * 4 + 1];
        memset(a, 0, sizeof(int) * (n * 4 + 1));
        buildTree(1, 0, n - 1);
    }
    
    int update(int node, int begin, int end, int i, int j, int val) {
        int p, q;
        if (i > end || j < begin) return a[node];
        if (begin >= i && end <= j) {
            return a[node] = val;
        }
        p = update(node * 2, begin, (begin + end) / 2, i, j, val);
        q = update(node * 2 + 1, (begin + end) / 2 + 1, end, i, j, val);
        return a[node] = (p + q);
    }
    
    void update(int i, int val) {
        update(1, 0, n - 1, i, i, val);
    }
    
    int query(int node, int begin, int end, int i, int j) {
        int p, q;
        if (i > end || j < begin) return 0;
        if (begin >= i && end <= j) return a[node];
        p = query(node * 2, begin, (begin + end) / 2, i, j);
        q = query(node * 2 + 1, (begin + end) / 2 + 1, end, i, j);
        return p + q;
    }
    
    int sumRange(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }
};
