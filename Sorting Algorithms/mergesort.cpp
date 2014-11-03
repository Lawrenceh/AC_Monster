#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void doMerge(int a[], int l, int m, int r, int b[]) {
    int index_1 = l, index_2 = m + 1, index = l;
    while (index <= r) {
        if (index_1 == m + 1) {
            b[index++] = a[index_2++];
        } else if (index_2 ==  r + 1) {
            b[index++] = a[index_1++];
        } else {
            if (a[index_1] < a[index_2]) {
                b[index++] = a[index_1++];
            } else {
                b[index++] = a[index_2++];
            }
        }
    }
    // copy arrays
    for (int i = l; i <= r; i ++) {
        a[i] = b[i];
    }
}

void merge(int a[], int l, int r, int b[]) {
    if (r > l) {
        int m = (r + l) >> 1;
        merge(a, l, m, b);
        merge(a, m + 1, r, b);
        doMerge(a, l, m, r, b);
    }
}

int main() {
    int a[] = {1,5,7,3,11,7,2,4,5,76,7,4,4,5,6};
    int n = sizeof(a) / sizeof(int);
    int *b = new int[n];
    merge(a, 0, n - 1, b);
    for (int i = 0; i < n - 1; i ++) {
        cout << a[i] << endl;
    }
    delete b;
    return 0;
}
