#include <iostream>
using namespace std;
int length;

void f(int n, int m, int *flag) {
    if (n < 1 || m < 1) return;
    if (n > m) n = m;
    if (n == m) {
        flag[n - 1] = 1;
        for (int i = 0; i < length; i ++) {
            if (flag[i] = 1) printf("%d\t", i + 1);
        }
        printf("\n");
        flag[n - 1] = 0;
    }
    flag[n - 1] = 1;
    f(n - 1, m - n, flag);
    flag[n - 1] = 0;
    f(n - 1, m, flag);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    length = n;
    int *flag = (int *)malloc(sizeof(int) * length);
    f(n, m, flag);
    free(flag);
    return 0;
}
