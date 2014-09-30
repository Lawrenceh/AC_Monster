#include <iostream>
using namespace std;

// flag = true at the very beginning
void test(const int data[], int start, int node, bool &flag) {
    if (flag && start < node) {
        int left = start;
        while (data[node] > data[left]) left ++;
        for (int i = left; i < node; i ++) {
            if (data[i] < data[node]) {
                flag = false;
                return;
            }
        }
        test(data, 0, left - 1, flag);
        test(data, left, node - 1, flag);
    }
}
