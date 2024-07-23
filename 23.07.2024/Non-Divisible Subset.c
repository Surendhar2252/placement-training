#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr = (int *)malloc(n * sizeof(int));
    int *count = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[arr[i] % k]++;
    }
    int result = count[0] > 0;
    for (int i = 1; i <= k / 2; i++) {
        if (i != k - i) result += count[i] > count[k - i] ? count[i] : count[k - i];
        else result++;
    }
    printf("%d\n", result);
    free(arr);
    free(count);
    return 0;
}
