/* Rabin-Karp
 * given string w, with length m
 *      hash(w[0 .. m-1])=(w[0]*2^(m-1)+ w[1]*2^(m-2)+···+ w[m-1]*2^0) mod q
 * and we define a rehash function:
 *      rehash(a,b,h) = ((h - a*2^(m-1))*2+b) mod q
 *
 * NOTE: we still need to compare strings char by char if equality of hash value is found
 * 
 * Complexity: O(m + n) avg and best, worst O(mn)
 */

#include <iostream>
using namespace std;

#define REHASH(a, b, h) ((((h) - (a) * d) << 1) + (b))

/* all modular operations are omitted below */
void rk(char *x, int m, char *y, int n) { // n >= m
    int d, hx, hy, i, j;

    /* computing d in #define */ 
    for (d = i = 1; i < m; ++ i) d = d << 1;

    /* preprocessing, computing hash values for pattern x and string y */
    for (hy = hx = i = 0; i < m; ++ i) {
        hx = ((hx << 1) + x[i]);
        hy = ((hy << 1) + y[i]);
    }

    j = 0;
    while (j <= n - m) {
        if (hx == hy && memcmp(x, y + j, m) == 0) 
            cout << j << endl;
        hy = REHASH(y[j], y[j + m], hy);
        ++ j;
    }
}
