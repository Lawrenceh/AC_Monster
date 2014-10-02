// brute force for loop
// O(nlogn)

// Recursion everytime with shifting right once
int CountOnes_in_a_row(int n) {
    int cnt = 0;
    if (n == 0) cnt = 0;
    else if (n > 1 && n < 10) cnt = 1;
    else {
        int highest = n;
        int bit = 0;
        while (highest >= 10) {
            highest /= 10;
            bit ++;
        }
        int weight = power(10, bit);
        // recursion starts
        if (highest == 1) {
            count = CountOnes_in_a_row(weight - 1) + CountOnes_in_a_row(n - weight) + n - weight + 1;
        }
        else count = highest * CountOnes_in_a_row(weight - 1) + CountOnes_in_a_row(n - highest * weight) + weight;
    }
    return cnt;
}

// http://www.cnblogs.com/jy02414216/archive/2011/03/09/1977724.html
// CountOnOnes with the bit position in the number!
// O(logn) - written here in JAVA
public long CountOne2(long n) {
    long count = 0;
    long i = 1;
    long current = 0,after = 0,before = 0;
    while((n / i) != 0) {           
        current = (n / i) % 10;
        before = n / (i * 10);
        after = n - (n / i) * i;
        if (current > 1)
            count = count + (before + 1) * i;
        else if (current == 0)
            count = count + before * i;
        else if(current == 1)
            count = count + before * i + after + 1;
        i = i * 10;
    }
    return count;
}
