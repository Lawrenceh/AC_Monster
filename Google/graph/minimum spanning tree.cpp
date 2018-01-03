/* Kruskal: using disjoint set */
MST-KRUSKAL(G, w)
1. for each vertex v in G.V
    MAKE-SET(v)
2. sort edges by weight w
3. for each edge (u, v) in G.E
    if FIND-SET(u) != FIND-SET(v)
        A = A + {(u, v)}
        UNION(u, v)
4. return A

complexity: O(ElgE) or O(ElgV), as |E| < |V|^2
sorting edges accounts for most of the time, while the disjoint set operations are negliable


/* Prim */
MST-PRIM(G, w, r) (r is root)
1. for each u in G.V
    u.key = inf
    u.pi = NIL
2. r.key = 0
   Q = G.V
3. while Q is not empty
    u = EXTRACT-MIN(Q)
    for each v in G.adj[u]
        if v in Q and w(u, v) < v.key // if v is unused yet, see if we need to update its key
            v.pi = u
            v.key = w(u, v) // note
4. A = {(v, v.pi): v in V - {r}}

NOTE: if we use priority_queue in STL, "decrease-key" operation is not implemented, therefore update-key step needs to be written in other ways: 1) implement our own data structure with decrease-key 2) use customized set 3) pointers!

NOTE: A hack for this - "push as we progress!". We don't assign the whole G.V to Q. We start with the root/source, then push the adj's found. There might be duplicates so it is not strictly correct. (Same story with Dijkstra)

complexity: O(VlgV + ElgV), from EXTRACT-MIN and DECREASE-KEY = O(ElgV) (|E| >= |V| in this case)

