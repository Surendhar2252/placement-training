#include <stdio.h>
#include <stdlib.h>

void absolutePermutation(int n, int k) {
    int *perm = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        if (i - k > 0 && !perm[i - k]) perm[i] = i - k;
        else if (i + k <= n && !perm[i + k]) perm[i] = i + k;
        else {
            printf("-1\n");
            free(perm);
            return;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", perm[i]);
    printf("\n");
    free(perm);
}

int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        absolutePermutation(n, k);
    }
    return 0;
}
