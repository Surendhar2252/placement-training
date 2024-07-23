#include <stdio.h>
#include <string.h>

long substrCount(int n, char *s) {
    long count = 0;
    for (int i = 0; i < n; i++) {
        int repeat = 0;
        while (i + 1 < n && s[i] == s[i + 1]) {
            repeat++;
            i++;
        }
        count += (repeat * (repeat + 1)) / 2;
    }
    for (int i = 1; i < n; i++) {
        int count_down = 0;
        while (i - count_down - 1 >= 0 && i + count_down < n && s[i + count_down] == s[i - count_down - 1] && s[i - count_down - 1] != s[i]) {
            count++;
            count_down++;
        }
    }
    return count;
}

int main() {
    int n;
    char s[100001];
    scanf("%d%s", &n, s);
    printf("%ld\n", substrCount(n, s));
    return 0;
}
