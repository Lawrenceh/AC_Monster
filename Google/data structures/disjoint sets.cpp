/* we need only these two arrays */
int father[MAX];
int rank[MAX];

void makeSet(int x) {
    father[x] = x;
    rank[x] = 0;
}

int findSet(int x) {
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
        father[y] = x;
    } else {
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
        father[x] = y;
    }
}

