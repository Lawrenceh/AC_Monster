FLOYD_WARSHALL: /* iterating via k, which represents for the intermediate node from {} to {1, 2, ..., n} O(V^3)*/

for k = 1 to n:
    for i = 1 to n:
        for j = 1 to n:
            d_{ij}^k = min(d_{ij}^(k-1), d_{ik}^(k-1) + d_{kj}^(k-1)) // NOTE: update the matrix each iteration



