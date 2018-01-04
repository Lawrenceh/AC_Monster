RELAX(u, v, w):
    if v.d > u.d + w(u, v):
        v.d = u.d + w(u, v)
        v.pi = u // predecessor

BELLMAN_FORD: /* detecting negative weight cycles O(VE)*/
1. initialize single source
2. for i = 1 to |G.V| - 1
    for each edge (u, v)
        RELAX(u, v, w)
3. for each edge (u, v)
    if still v.d > u.d + w(u, v)
        return false // negative weight cycle
return true // predecessors kept in attribute "pi" of each node


DAG_SHORTEST_PATH: /* DAG O(V+E)*/
    1. topological sorting of G
    2. initialize all "root" nodes to be of distance 0, and all others inf
    3. for each u in topologically sorted order:
        for each v in G.adj[u]:
            RELAX(u, v, w)

/* This could be extended to getting the DAG_LONGEST_PATH, or critical path */
INITIALIZE':
    all other nodes of distance -inf

RELAX'(u, v, w):
    if v.d < u.d + w(u, v):
        v.d = u.d + w(u, v)
        v.pi = u // predecessor

DIJKSTRA: /* positive weight edges directed graph O((V+E)lgV) using binary heap */
1. initialize single source
2. Q = G.V
   while Q is not empty:
       u = EXTRACT-MIN(Q)
       for each vertex v in G.adj[u]:
           RELAX(u, v, w)

