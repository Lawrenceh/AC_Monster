/* TLE unoptimized solution: brute-force */
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int i = 0, j = 0, c1 = 0, c2 = 0;
        while (c1 < n1) {
            if (s1[i] == s2[j]) {
                j ++;
            }
            i ++;
            if (i == s1.size()) {
                i = 0;
                c1 ++;
            }
            if (j == s2.size()) {
                j = 0;
                c2 ++;
            }
        }
        return c2 / n2;
    }
};


/* same idea in JAVA gets AC */
public class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        char[] array1 = s1.toCharArray(), array2 = s2.toCharArray();
        int count1 = 0, count2 = 0, i = 0, j = 0;
        
        while (count1  n1) {
            if (array1[i] == array2[j]) {
                j++;
                if (j == array2.length) {
                    j = 0;
                    count2++;
                }
            }
            i++;
            if (i == array1.length) {
                i = 0;
                count1++;
            }
        }
        
        return count2  n2;
    }
}
