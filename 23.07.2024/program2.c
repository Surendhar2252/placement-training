#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, a, b, k;
    scanf("%d%d", &n, &m);
    long *arr = (long *)calloc(n + 1, sizeof(long));
    while (m--) {
        scanf("%d%d%d", &a, &b, &k);
        arr[a] += k;
        if (b + 1 <= n) arr[b + 1] -= k;
    }
    long max = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        x += arr[i];
        if (x > max) max = x;
    }
    printf("%ld\n", max);
    free(arr);
    return 0;
}
