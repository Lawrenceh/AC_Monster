/* pseudo code */
DAG_SHORTEST_PATH:
    1. topological sorting of G
    2. initialize all "root" nodes to be of distance 0, and all others inf
    3. for each u in topologically sorted order:
        for each v in G.adj[u]:
            RELAX(u, v, w)

RELAX(u, v, w):
    if v.d > u.d + w(u, v):
        v.d = u.d + w(u, v)
        v.pi = u // predecessor

/* This could be extended to getting the DAG_LONGEST_PATH, or critical path */
INITIALIZE':
    all other nodes of distance -inf

RELAX'(u, v, w):
    if v.d < u.d + w(u, v):
        v.d = u.d + w(u, v)
        v.pi = u // predecessor
