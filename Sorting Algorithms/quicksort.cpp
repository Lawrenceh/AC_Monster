#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int partition(int a[], int l, int r) {
    int i = l, j = r;
    int pivot = a[l];
    while (i < j) {
        while (i < j && a[j] >= pivot) j --;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= pivot) i ++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = pivot;
    return i;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int k = partition(a, l, r);
        quicksort(a, l, k - 1);
        quicksort(a, k + 1, r);
    }
}

int main() {
    int a[] = {3,5,6,2,3,1,4,5,7,8,3,4,5,6,1,12,3,3,2,3,4,1,3,5,76,3,3};
    int n = sizeof(a) / sizeof(int);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
}
