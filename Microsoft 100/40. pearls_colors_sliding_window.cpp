int shortestFullColor(int a[], int n, int m) {
    // here it's different from the question's notation
    // n := total pearls
    // m := total colors
    int c[m], cnt = m;
    int h = 0, t = 0;
    int min = n;
    while (1) {
        while (cnt > 0 && h < n) {
            if (c[a[h] == 0) cnt --;
            c[a[h]] ++;
            h ++;
        }
        if (h >= n) return min;
        while (1) {
            c[a[t]] --;
            if (c[a[t]] == 0) break;
            t ++;
        }
        if (min > h - t) min = h - t;
        t ++;
        cnt ++;
    }
}
