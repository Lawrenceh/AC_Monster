#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define PARENT(i) ((i - 1) >> 1)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

/*
 * MIN HEAP
 */

void swap(int &x, int &y) {
    x ^= y;
    y ^= x;
    x ^= y;
}

void heapify(int a[], int index, int n) {
    int l = LEFT(index);
    int r = RIGHT(index);
    int maxindex = index;
    if (l < n && a[l] > a[index]) maxindex = l;
    if (r < n && a[r] > a[maxindex]) maxindex = r;
    if (maxindex != index) {
        swap(a[index], a[maxindex]);
        heapify(a, maxindex, n);
    }
}

void buildheap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i --) {
        heapify(a, i, n);
    }
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
}

void heapsort(int a[], int n) {
    buildheap(a, n);
    for (int i = n - 1; i > 0; i --) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}


int main() {
    int a[] = {1,5,7,3,11,7,2,4,5,76,7,4,4,5,6};
    int n = sizeof(a) / sizeof(int);
    cout << n << endl;
    heapsort(a, n);
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
}
