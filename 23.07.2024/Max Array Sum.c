#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubsetSum(int *arr, int n) {
    int incl = arr[0], excl = 0, new_excl;
    for (int i = 1; i < n; i++) {
        new_excl = max(incl, excl);
        incl = excl + arr[i];
        excl = new_excl;
    }
    return max(incl, excl);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", maxSubsetSum(arr, n));
    free(arr);
    return 0;
}
