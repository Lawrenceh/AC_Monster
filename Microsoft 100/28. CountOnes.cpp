// normal O(k) algorithm

// dynamic table
#include <iostream>
using namespace std;

int bitCount(unsigned int n) {
    unsigned char bt[256] = {0};
    for (int i = 0; i < 256; i ++) {
        bt[i] = (i & 1) + bt[i / 2];
    }
    unsigned int c = 0;
    // convert!
    unsigned char *p = (unsigned char *)&n;
    c = bt[p[0]] + bt[p[1]] + bt[p[2]] + bt[p[3]];
    return c;
}

int main() {
    int n;
    cout << bitCount(100);
    return 0;
}

// static table - 4bit
int bitCount(unsigned int n) {
    unsigned int table[16] = {
        0, 1, 1, 2,
        1, 2, 2, 3,
        1, 2, 2, 3,
        2, 3, 3, 4
    };
    unsigned int count = 0;
    while (n) {
        count += table[n & 0xf];
        n >>= 4;
    }
    return count;
}

// parallel algorithm
int BitCount4(unsigned int n) { 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ; 
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ; 
    n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ; 
    n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ; 
    return n ; 
}
