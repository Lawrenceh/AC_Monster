bool path[MAXN][MAXN], visit[MAXN];
int match[MAXN]; // init to be -1
bool SearchPath(int s) {
    for (int i = 0; i < m; i ++) {
        if (path[s][i] && !visit[i]) {
            visit[i] = true;
            if (match[i] == -1 || SearchPath(match[i], m)) {
                match[i] = s;
                return true;
            }
        }
    }
    return false;
}

int main() {
    sum = 0;
    for (int i = 0; i < n; i ++) {
        memset(visit, 0, sizeof(visit));
        if (SearchPath(i)) sum ++;
    }
    return 0;
}

