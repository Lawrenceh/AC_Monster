// NOTE: different graph representations may result in different complexities

/* BFS */
for each vertex u in G.V
    u.color = WHITE
    u.d = inf
    u.pi = NIL
s.color = GRAY
s.d = 0
s.pi = NIL

Q = empty queue
ENQUEUE(Q, s)
while Q is not empty
    u = DEQUEUE(Q)
    for each v in G.adj[u]
        if v.color == WHITE // if unvisited
            v.color = GRAY // mark as being visited
            v.d = u.d + 1
            v.pi = u
            ENQUEUE(Q, v)
    u.color = BLACK // mark as complete


/* DFS */
DFS(G)
for each vertex u in G.V
    u.color = WHITE
    u.pi = NIL
time = 0
for each vertex u in G.V
    if u.color == WHITE
        DFS-VISIT(G, u)

DFS-VISIT(G, u)
u.color = GRAY // mark as being visited
for each v in G.adj[u]
    if v.color == GRAY
        raise cycle detected exception
    if v.color == WHITE // if unvisited
        v.pi = u
        DFS-VISIT(G, v)
u.color = BLACK // mark as complete


/* Topological sort: dfs based algorithm */
1. Call DFS(G) to compute finishing times for each vertex
2. return the reverse of the finishing times sequence vertices


/* Strongly connected components: Kosarajus algorithm - 2 pass DFS */
1. Call DFS(G') to compute the finishing times for each vertex (G' is G transpose or reverse)
2. Call another DFS(G) in order of previous topological sorting result (on G')

