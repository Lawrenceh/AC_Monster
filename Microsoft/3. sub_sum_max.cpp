#include <iostream>
using namespace std;

int a[] = {1, -2, 3, 10, -4, 7, 2, -5};

int main() {
    int l = sizeof(a) / sizeof(int);
    int sum = 0;
    int max = -(1 << 31);
    int x = 0; int y = 0; int pos = 0;
    for (int i = 0; i < l; i ++) {
        sum += a[i];
        if (sum > max) {
            max = sum;
            y = i;
            if (pos != 0) {
                x = pos;
            }
        }
        if (sum <= 0) {
            sum = 0;
            pos = i + 1;
        }
    }
    cout << x << " : " << y << endl;
    cout << max << endl;
    return 0;
}
