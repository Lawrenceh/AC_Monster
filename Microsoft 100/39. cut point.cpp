void findCutPoints() {
    int sub = 0;
    for (int i = 0; i < nodeNum; i ++) {
        sub = 0;
        checkCut(i, sub);
        if (sub != 1) {
            cout << i << endl;
        }
    }
}

void checkCut(int x, int &sub) {
    memset(flag, 0, sizeof(flag));
    flag[x] = true;
    for (int i = 0; i < nodeNum; i ++) {
        if (flag[i] == false) {
            sub ++;
            dfs(i);
        }
    }
}

void dfs(int x) {
    flag[x] = true;
    for (int i = 0; i < num[x]; i ++) {
        if (flag[graph[x][i]] == false) dfs(graph[x][i]);
    }
}
