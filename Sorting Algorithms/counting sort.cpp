#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void csort(int a[], int b[], int n) {
    int *c = new int[10001]{0};
    for (int i = 0; i < n; i ++) c[a[i]] ++;
    for (int i = 0; i < 10000; i ++) c[i + 1] = c[i] + c[i + 1];
    int j = n - 1;
    while (j >= 0) {
        b[c[a[j]] - 1] = a[j]; 
        c[a[j]] --;
        j --;
    }
}

int main() {
    int a[] = {12,3,4,3,2,1,65,7,8,4,3,5,7,8,9,1};
    int n = sizeof(a) / sizeof(int);
    int *b = new int[n]{0};
    csort(a, b, n);
    for (int i = 0; i < n; i ++) {
        cout << b[i] << " ";
    }
}
