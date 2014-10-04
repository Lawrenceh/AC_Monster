#include <stdio.h>
 
#define MAX 100001
 
void Make_Set (int father[], int rank[], int n){
    int i;
    for (i=1; i<=n; ++i){
        father[i] = i;
        rank[i] = 0;
    }
}
 
int Find_Set (int father[], int x){
    if (father[x] != x){
        father[x] = Find_Set (father, father[x]);
    }
    return father[x];
}
 
void Union (int father[], int rank[], int x, int y){
    x = Find_Set (father, x);
    y = Find_Set (father, y);
    if (x == y)
        return;
    if (rank[x] > rank[y]){
        father[y] = x;
        rank[x] += rank[y];
    }
    else{
        if (rank[x] == rank[y])
            ++rank[y];
        father[x] = y;
    }
}
 
int main(void){
    int n;
    int m;
    int father[MAX];
    int rank[MAX];
    int f, t;
    int nSet;
    int i;
 
    while (scanf ("%d", &n) != EOF && n != 0){
        scanf ("%d", &m);
        Make_Set (father, rank, n);
        while (m-- != 0){
            scanf ("%d%d", &f, &t);
            Union (father, rank, f, t);
        }
        nSet = 0;
        for (i=1; i<=n; ++i){
            if (father[i] == i)
                ++nSet;
        }
        printf ("%d\n", nSet);
    }
 
    return 0;
}
