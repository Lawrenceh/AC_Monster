#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    char a[] = "ababcabcabababa";
    int n = strlen(a);
    char b[] = "ababa";
    int m = strlen(b);
    // next
    int *p = new int[m];
    p[0] = -1;
    int i = 0;
    int j = -1;
    while (i < m - 1) {
        if (j == -1 || b[i] == b[j]) {
            ++ i;
            ++ j;
            p[i] = j;
        } else {
            j = p[j];
        }
    }
    // kmp
    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (j == -1 || a[i] == b[j]) {
            ++ i;
            ++ j;
        } else {
            j = p[j];
        }
    }
    delete []p;
    if (j == m) cout << i - j << endl;
    else cout << "-1" << endl;
    return 0;
}
