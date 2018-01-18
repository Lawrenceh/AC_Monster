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

    if (p1 == -1) return M[node] = p2;
    if (p2 == -1) return M[node] = p1;
    if (A[p1] <= A[p2]) return M[node] = p1;
    return M[node] = p2;
}

Complexity: <O(N), O(logN)> (preprocessing time, query time)
