#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

#define LEN 500000
#define K 100

#define LEFTSON(i) (2 * i + 1)
#define RIGHTSON(i) (2 * (i + 1))
#define PARENT(i) ((i - 1) / 2)

// qsort
void swap (int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int partition(int *a, int left, int right) {
    int pivot = a[left];
    int i = left;
    int j = right;

    while (i < j) {
        while (i < j && a[j] >= pivot) -- j;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] < pivot) ++ i;
        if (i < j) a[j--] = a[i];
    }
    a[i] = pivot;
    return i;
}

void qsort(int *a, int left, int right) {
    int i = 0;
    if (left < right) {
        i = partition(a, left, right);
        qsort(a, left, i - 1);
        qsort(a, i + 1, right);
    }
}

// qselect
void qselect(int *a, int left, int right, int k) {
    int i = 0;
    if (left < right) {
        i = partition(a, left, right);
        if (i + 1 <= k) qselect(a, i + 1, right, k);
        else qselect(a, left, i - 1, k);
    }
}

// qselect
void find_Kmin_num_2(int *a, int size, int k) {
    qselect(a, 0, size - 1, k);
    for (int i = 0; i < k; ++ i) printf("%d\t", a[i]);
    printf("\n");
}

// qsort
void find_Kmin_num_1(int *a, int size, int k) {
    qsort(a, 0, size - 1);
    for (int i = 0; i < k; ++ i) printf("%d\t", a[i]);
    printf("\n");
}

void build_minheap(int *a, int size) {
    int i = PARENT(size);
    // start build process from the first non-leaf node
    for (; i >= 0; -- i) min_heapify(a, i, size - 1);
}

void min_heapify(int *a, int left, int right) {
    int child = 0;
    int parent = left;
    int tmp = a[parent];
    for (; LEFTSON(parent) <= right; parent = child) {
        child = LEFTSON(parent);
        if (child != parent && a[child] > a[child + 1]) child ++;
        if (a[child] < tmp) a[parent] = a[child];
        else break;
    }
    a[parent] = tmp;
}

void find_Kmin_num_4(int *a, int size, int k) {
    int i = 0;
    build_minheap(a, size - 1);
    for (i = 0; i < k; ++ i) {
        // min = a[0];
        a[0] = a[size - 1 - i];
        min_heapify(a, 0, size - 2 - i);
    }
}

int main() {
    int a[LEN];
    int b[LEN];
    int d[LEN];

    srand((int)time(NULL));
    for (int i = 0; i < LEN; ++ i) {
        a[i] = rand() % LEN;
        b[i] = a[i];
        d[i] = a[i];
    }

    clock_t _start = clock();
    find_Kmin_num_1(a, LEN, k);
    double times_1 = (double)(clock() - _start) / CLOCKS_PER_SEC;

    clock_t _start = clock();
    find_Kmin_num_2(b, LEN, k);
    double times_2 = (double)(clock() - _start) / CLOCKS_PER_SEC;

    clock_t _start = clock();
    find_Kmin_num_4(d, LEN, k);
    double times_4 = (double)(clock() - _start) / CLOCKS_PER_SEC;
    return 0;
}
