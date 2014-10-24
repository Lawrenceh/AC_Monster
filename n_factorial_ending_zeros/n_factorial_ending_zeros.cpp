int CalZeroNum(int n) {
    int num = 0;
    int b = 1;
    while (1) {
        b *= 5;
        num += n / b;
        if (b > n) break;
    }
    return num;
}
