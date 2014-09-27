#include <iostream>
using namespace std;

#define REHASH(a, b, h) ((((h) - (a) * d) << 1) + (b))

void rk(char *x, int m, char *y, int n) {// n >= m
    int d, hx, hy, i, j;

    for (d = i = 1; i < m; ++ i) {
        d = d << 1;
    }
    for (hy = hx = i = 0; i < m; ++ i) {
        hx = ((hx << 1) + x[i]);
        hy = ((hy << 1) + y[i]);
    }

    j = 0;
    while (j <= n - m) {
        if (hx == hy && memcmp(x, y + j, m) == 0)
            cout << j << endl;
        hy = REHASH(y[j], y[j + m], hy);
        ++ j;
    }
}

int main() {
    return 0;
}
