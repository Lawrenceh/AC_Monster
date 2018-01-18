/* Copyright: post from Tianyi Cui's writings */
w[i] - worth value
c[i] - volume cost
n[i] - number of this type

1. 0-1 knapsack (only one knapsack for each):
    f[i][v] = max{f[i - 1][v], f[i - 1][v - c[i]] + w[i]}

optimized: from O(VN) to O(V)

    for i = 1 to N
        for v = V to 0 // backwards
            f[v] = max{f[v], f[v - c[i]] + w[i]}

Note: if pack is required to be filled up, f[0] = 0, f[1] = f[2] = ... = f[V] = -inf
      otherwise, all are 0's.

2. infinite number of packs for each:
    f[i][v] = max{f[i - 1][v], f[i][v - c[i]] + w[i]}

This is O(V * sigma(V / c[i]))!

optimized: from above to O(VN)

    for i = 1 to N
        for v = 0 to V // only difference
            f[v] = max{f[v], f[v - c[i]] + w[i]}

3. each item only have n[i] pieces available:
    f[i][v] = max{f[i - 1][v - k * c[i]] + k * w[i]}, 0 <= k <= min(n[i], j / c[i])

Could be converted to "type 1" problems.

Also, we could use "binary representation" to lower it logarithmically: (for example problem 2)
    - convert ith item into a bunch of < 2^k * c[i], 2^k * w[i]> items (c[i] * 2^k <= V)

We could also use "monotone queue" to lower complexity to O(VN)!


4. Variants:
    a) print out the solution: use g[i][v] = 0, which means ith item not chosen
                                           = 1, which means the second one is picked
        i = N
        v = V
        while (i > 0)
            if (g[i][v] == 0)
                print "ith item is not picked"
            else if (g[i][v] == 1)
                print "ith item is picked"
                v = v - c[i]
            decrement i

    NOTE: we could also use f[i][v] == f[i - 1][v], and similar equations to check if 1st or 2nd is used

    b) count number of best solution

        for i = 1 to N
           for v = 0 to V
                f[i][v] = max{f[i - 1][v], f[i - 1][v - c[i]] + w[i]}
                g[i][v] = 0
                if(f[i][v] == f[i - 1][v])
                    inc(g[i][v], g[i - 1][v])
                if(f[i][v] == f[i - 1][v - c[i]] + w[i])
                    inc(g[i][v], g[i - 1][v - c[i]])
