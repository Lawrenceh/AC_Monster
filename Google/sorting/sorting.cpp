/* mergesort vs quicksort */
- quicksort is in-place, mergesort needs O(N) auxilliary space
- quicksort has good locality of reference, which is extremely important when secondary memory comes into play (sorting files)
- quicksort has tail recursion, which could be optimized by optimizer
- mergesort works perfectly when we deal with linked list, because memory allocation is not continuous
- mergesort avoids the need for random index access used in quicksort when we deal with linked list
- mergesort is stable
- mergesort is a must when RAM is not big enough for all intermediate results

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

// The only significant advantage that bubble sort has over most other implementations, even quicksort, but not insertion sort, is that the ability to detect that the list is sorted efficiently is built into the algorithm. When the list is already sorted (best-case), the complexity of bubble sort is only O(n). By contrast, most other algorithms, even those with better average-case complexity, perform their entire sorting process on the set and thus are more complex. However, not only does insertion sort have this mechanism too, but it also performs better on a list that is substantially sorted (having a small number of inversions).
void BubbleSort(int a[], int n) {
    // swapped is added for O(n) best case
    bool swapped = true;
    for (int i = 0; i < n; i ++) {
        if (!swapped) return;
        for (int j = n - 1; j > i; j --) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                swapped = true;
            }
        }
    }
}

// Although it is one of the elementary sorting algorithms with O(n2) worst-case time, insertion sort is the algorithm of choice either when the data is nearly sorted (because it is adaptive) or when the problem size is small (because it has low overhead). For these reasons, and because it is also stable, insertion sort is often used as the recursive base case (when the problem size is small) for higher overhead divide-and-conquer sorting algorithms, such as merge sort or quick sort.
void InsertionSort(int a[], int n) { //adaptive and low overhead
    int j = 0;
    for (int i = 1; i < n; i ++) {
        int key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key;
    }
}


void merge(int a[], int l, int mid, int r) {
    int b[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }
    for (int kk = 0; kk < k; kk ++) {
        a[l + kk] = b[kk];
    }
}

// T(n) = 2 * T(n / 2) + cn
void MergeSort(int a[], int l, int r) {
    if (l >= r) return; // infinite loop would've been caused
    int mid = (r - l) / 2 + l;
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}


// [l, i] < key, i + 1 = key, [i + 2, r] >= key
int partition(int a[], int l, int r) {
    int key = a[r];
    int i = l - 1;
    int j = l;
    while (j < r) {
        if (a[j] < key) {
            i ++;
            swap(a[j], a[i]);
        }
        j ++;
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}


// [l, i] < key, [i + 1, k] = key, [k + 1, r] > key
pair<int, int> threewaypartition(int a[], int l, int r) {
    int key = a[r];
    int i = l - 1, k = l - 1, j = l;
    while (j < r) {
        if (a[j] == key) {
            k ++;
            swap(a[j], a[k]);
        } else if (a[j] < key) { /* incorrect: i ++; k ++; swap(a[j], a[i]); swap(a[j], a[k]); */
            i ++;
            k ++;
            swap(a[j], a[k]);
            swap(a[i], a[k]);
        }
        j ++;
    }
    swap(a[k + 1], a[r]);
    return make_pair(i + 1, k + 1);
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        // int pivot = partition(a, l, r);
        // QuickSort(a, l, pivot - 1);
        // QuickSort(a, pivot + 1, r);
        pair<int, int> mp = threewaypartition(a, l, r);
        int lpivot = mp.first;
        int rpivot = mp.second;
        QuickSort(a, l, lpivot - 1);
        QuickSort(a, rpivot + 1, r);
    }
}


void heapify(int a[], int k, int n) { // heapify assumes all below sub-structure is already heapified
    int left = k * 2 + 1;
    int right = k * 2 + 2;
    int largest = k;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != k) {
        swap(a[k], a[largest]);
        heapify(a, largest, n);
    }
}

void BuildHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i --) {
        heapify(a, i, n);
    }
}

// heap sort - max heap
void HeapSort(int a[], int n) {
    BuildHeap(a, n);
    for (int i = n - 1; i > 0; i --) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

// counting sort
void CountingSort(int a[], int n) {
    int c[10001];
    int b[n];
    memset(c, 0, sizeof(int) * 10001);
    memset(b, 0, sizeof(int) * n);
    for (int i = 0; i < n; i ++) {
        c[a[i]] ++;
    }
    for (int i = 1; i < 10001; i ++) {
        c[i] = c[i] + c[i - 1];
    }
    for (int i = n - 1; i >= 0; i --) {
        b[--c[a[i]]] = a[i];
    }
    // copy results
    for (int i = 0; i < n; i ++) {
        a[i] = b[i];
    }
}


int main() {
    int a[] = {1,5,7,3,11,7,2,4,5,76,7,4,4,5,6};
    //int a[] = {3,1,5,7,2,4,9,6};  
    int n = sizeof(a) / sizeof(int);
    CountingSort(a, n);
    for (int i = 0; i < n; i ++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
