// https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/

Notations:
Suppose that an algorithm has preprocessing time f(n) and query time g(n). The notation for the overall complexity for the algorithm is <f(n), g(n)>.

Range Minimum Query(RMQ):
Given an array A[0, N-1] find the position of  the element with the minimum value in interval [i, j].

1. Trivial algorithms for RMQ (dp optimized): <O(N2), O(1)>

   void process1(int M[MAXN][MAXN], int A[MAXN], int N) {
       int i, j;
       for (i =0; i < N; i++)
           M[i][i] = i;
       for (i = 0; i < N; i++)
           for (j = i + 1; j < N; j++)
               if (A[M[i][j - 1]] < A[j])
                   M[i][j] = M[i][j - 1];
               else
                   M[i][j] = j;
   }


2. Sqrt solution: <O(N), O(sqrt(N))> - split the vector in sqrt(N) pieces

    this proves to be taking at most 3 * sqrt(N) operations per query

    For example, to get RMQ(2,7) in the above example we should compare A[2], A[M[1]], A[6] and A[7] and get the position of the minimum value.


3. Sparse Table algorithm (ST): (also dp)

    M[i][j]: starting at i, with length 2^j

    M[i][j] = M[i][j - 1], if A[M[i][j - 1]] <= A[M[i + 2 ^ (j - 1)][j - 1]]
            = M[i + 2 ^ (j - 1)][j - 1], else ..

/* preprocessing */
void process2(int M[MAXN][LOGMAXN], int A[MAXN], int N) {
    int i, j;

    for (i = 0; i < N; i++)
        M[i][0] = i;

    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

/* query */
k = floor(log(j - i + 1)) 

RMQ(i, j) = M[i][k], if A[M[i][k]] <= A[M[j - 2 ^ k + 1][k]]
          = M[j - 2 ^ k + 1][k], else ..



/* segment tree solution: see data structures/segment tress */



