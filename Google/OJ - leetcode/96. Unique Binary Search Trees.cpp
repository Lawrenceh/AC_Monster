/* dp: catalan number */


/* CATALAN number:
 * 1. Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
 * 2. Count the number of unique Binary Search Trees with n keys
 * 3. The number of paths with 2n steps on a rectangular grid from bottom left, i.e., (n-1, 0) to top right (0, n-1) that do not cross above the main diagonal.
 */

class Solution {
public:
    int numTrees(int n) {
        int a[n + 1]; // value for length i seq
        memset(a, 0, sizeof(int) * (n + 1));
        a[0] = 1; // empty tree is also 1
        a[1] = 1;
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j <= i - 1; j ++) {
                a[i] += a[j] * a[i - j - 1];
            }
        }
        return a[n];
    }
};
