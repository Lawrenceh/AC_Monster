#include <iostream>
using namespace std;

void insertion(int *a, int n) {
    int key = 0;
    for (int i = 0; i < n; i ++) {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {1,5,7,3,11,10,-1,8,9,3,4,5,76,7,4,4,5,6};
    int n = sizeof(a) / sizeof(int);
    insertion(a, n);
    for (int i = 0; i < n; i ++) {
        cout << a[i] << endl;
    }
}
