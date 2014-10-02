// assume char to be ASCII in an array
char firstSingle(char *str) {
    int a[255];
    memset(a, 0, 255 * sizeof(int));
    char *p = str;
    while (*p != '\0') {
        a[*p] ++;
        p ++;
    }
    p = str;
    while (*p != '\0') {
        if (a[*p] == 1) return *p;
    }
    return '\0';
}
